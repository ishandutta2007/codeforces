#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,INF=0x3f3f3f3f;
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
	}
}
int n,f[N],g[N],ff[N],gg[N];
char s[N>>1],t[N>>1];
void proc(int i)
{
	using pam::fail;using pam::slink;using pam::dif;using pam::len;
	for(int u=pam::last;u>1;u=slink[u])
	{
		g[u]=f[i-len[slink[u]]-dif[u]];gg[u]=i-len[slink[u]]-dif[u];
		if(fail[u]!=slink[u]&&g[u]>g[fail[u]])g[u]=g[fail[u]],gg[u]=gg[fail[u]];
		if(f[i]>g[u]+1)f[i]=g[u]+1,ff[i]=gg[u];
	}
	if(i&1)f[i]=INF;
	else if(pam::s[i-1]==pam::s[i-2]&&f[i]>f[i-2])f[i]=f[i-2],ff[i]=i-2;
}
int main()
{
	scanf("%s%s",s,t);
	while(s[n])++n;
	n<<=1;
	pam::init();
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	f[0]=0;ff[0]=-1;
	F(i,0,n>>1)pam::insert(s[i]),proc(2*i+1),pam::insert(t[i]),proc(2*i+2);
	if(f[n]==INF)return puts("-1"),0;
	printf("%d\n",f[n]);
	for(int i=n;~i;i=ff[i])if(i-ff[i]>2)printf("%d %d\n",(ff[i]>>1)+1,i>>1);
	return 0;
}