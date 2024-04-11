#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,to[N+1][26],ind=1,fail[N+1],cnt[N+1][2],q[N],qf,qr,f[N],r[N];
char t[N+1],s[N+1];
long long ans=0;
void reverse(char *str)
{
	int len=0;
	while(str[len])++len;
	F(i,0,len/2)str[i]^=str[len-1-i]^=str[i]^=str[len-1-i];
}
void insert(const char *str,int type)
{
	int j=0;
	for(int i=0;str[i];++i)
	{
		int x=str[i]-97;
		if(!to[j][x])to[j][x]=ind++;
		j=to[j][x];
	}
	++cnt[j][type];
}
void build()
{
	F(i,0,26)if(to[0][i])q[qr++]=to[0][i];
	while(qf<qr)
	{
		int u=q[qf++];
		cnt[u][0]+=cnt[fail[u]][0];
		cnt[u][1]+=cnt[fail[u]][1];
		F(i,0,26)if(to[u][i])fail[q[qr++]=to[u][i]]=to[fail[u]][i];
		else to[u][i]=to[fail[u]][i];
	}
}
int main()
{
	int m=0;
	scanf("%s",t);
	while(t[m])++m;
	read(n);
	F(i,0,n)
	{
		scanf("%s",s);
		insert(s,0);
		reverse(s);
		insert(s,1);
	}
	build();
	for(int i=0,j=0;t[i];++i)
	{
		j=to[j][t[i]-97];
		f[i]=cnt[j][0];
	}
	reverse(t);
	for(int i=0,j=0;t[i];++i)
	{
		j=to[j][t[i]-97];
		r[m-1-i]=cnt[j][1];
	}
	F(i,0,m-1)ans+=(long long)f[i]*r[i+1];
	printf("%lld\n",ans);
	return 0;
}