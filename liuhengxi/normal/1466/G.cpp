#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2e6+5,MOD=1000000007;
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
int n,q,m,next[M],pow2[N],ipow2[N],pre[27][N];
char s[N],t[N],ss[M],w[M];
void dfs(int k)
{
	if(k==0)
	{
		for(int i=0;s[i];++i)ss[m++]=s[i];
		return;
	}
	dfs(k-1);
	ss[m++]=t[k-1];
	dfs(k-1);
}
int main()
{
	F(i,pow2[0]=1,N)pow2[i]=(pow2[i-1]<<1)%MOD;
	F(i,ipow2[0]=1,N)ipow2[i]=int(ipow2[i-1]*500000004ll%MOD);
	int k=0;
	read(n);read(q);
	scanf("%s",s);scanf("%s",t);
	while(s[m])++m;
	while((m<<1|1)<M)(m<<=1)|=1,++k;
	m=0;
	if(k>n)k=n;
	dfs(k);
	F(j,0,26)F(i,0,n)pre[j][i+1]=(pre[j][i]+(t[i]=='a'+j)*pow2[n-i-1])%MOD;
	while(q--)
	{
		int u=0,len=0,wlen=0,o=0,j1=0;
		long long ans=0;
		read(u);
		scanf("%s",w);
		while(w[wlen])++wlen;
		while(s[len])++len;
		for(k=0;len<wlen;(len<<=1)|=1,++k);
		if(k>u){puts("0");continue;}
		for(int i=1,j=0;i<wlen;next[++i]=j)
		{
			while(j&&w[i]!=w[j])j=next[j];
			if(w[i]==w[j])++j;
		}
		for(int i=0;i<len;++i)
		{
			while(j1&&ss[i]!=w[j1])j1=next[j1];
			if(ss[i]==w[j1])++j1;
			if(j1==wlen)++o;
		}
		ans=(long long)o*pow2[n-k]%MOD;
		F(mid,0,26)
		{
			o=0;
			for(int i=0,j=j1;i<wlen;++i)
			{
				char x=i?ss[i-1]:char('a'+mid);
				while(j&&x!=w[j])j=next[j];
				if(x==w[j])++j;
				if(j==wlen)++o;
			}
			ans+=(long long)o*(pre[mid][u]-pre[mid][k]+MOD)%MOD;
		}
		ans=ans%MOD*ipow2[n-u]%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}