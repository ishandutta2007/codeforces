#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=1000000007;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int cnt[N];
namespace pam
{
	int s[N],n,last,ind;
	int to[N][26],len[N],fail[N],dif[N],slink[N];
	void init(){fail[0]=1;dif[0]=1;len[1]=-1;ind=2;}
	void insert(char cc)
	{
		int c=cc-'a',now=last;
		s[n]=c;
		while(n-len[now]-1<0||s[n-len[now]-1]!=s[n])now=fail[now];
		if(!to[now][c])
		{
			int u=fail[now];
			len[ind]=len[now]+2;
			while(s[n-len[u]-1]!=s[n])u=fail[u];
			fail[ind]=to[u][c];
			dif[ind]=len[ind]-len[fail[ind]];
			slink[ind]=dif[fail[ind]]!=dif[ind]?fail[ind]:slink[fail[ind]];
			to[now][c]=ind++;
		}
		++n;
		last=to[now][c];
		++cnt[last];
	}
};
using pam::len;
using pam::dif;
using pam::fail;
using pam::slink;
int n,f[N],g[N];
char s[N];
void proc(int i)
{
	for(int u=pam::last;u>1;u=slink[u])
	{
		if(fail[u]!=slink[u])g[u]=(f[i+1-len[slink[u]]-dif[u]]+g[fail[u]])%MOD;
		else g[u]=f[i+1-len[slink[u]]-dif[u]];
		if(i&1)f[i+1]=(f[i+1]+g[u])%MOD;
	}
}
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	pam::init();
	f[0]=1;
	F(i,0,n>>1)pam::insert(s[i]),proc(i<<1),pam::insert(s[n-1-i]),proc(i<<1|1);
	printf("%d\n",f[n]);
	return 0;
}