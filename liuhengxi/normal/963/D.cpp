#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
char s[N],tt[N];
int n,k[N],t[N],to[N][26],fail[N],nxt[N],ind,q[N],qf,qr,cnt[N],len[N];
bool is[N];
vector<int> occ[N];
int insert(char *str)
{
	int j=0;
	for(int x=*str-'a';*str;x=*++str-'a')j=to[j][x]?to[j][x]:to[j][x]=++ind;
	return is[j]=true,j;
}
void build()
{
	F(i,0,26)if(to[0][i])q[qr++]=to[0][i];
	while(qf<qr)
	{
		int u=q[qf++];
		nxt[u]=is[fail[u]]?fail[u]:nxt[fail[u]];
		F(i,0,26)if(to[u][i])fail[q[qr++]=to[u][i]]=to[fail[u]][i];
		else to[u][i]=to[fail[u]][i];
	}
}
int main()
{
	scanf("%s",s);
	F(i,0,read(n))
	{
		read(k[i]);
		scanf("%s",tt);
		t[i]=insert(tt);
		while(tt[len[i]])++len[i];
	}
	build();
	for(int i=0,u=0;s[i];++i)
	{
		int x=s[i]-'a';
		u=to[u][x];
		for(int v=is[u]?u:nxt[u];v;v=nxt[v])occ[v].push_back(i);
	}
	F(i,0,n)
	{
		int m=(int)(occ[t[i]].size()),kk=k[i];
#define k kk
		if(--k>=m)puts("-1");
		else
		{
			int ans=INF;
			F(j,0,m-k)ans=min(ans,occ[t[i]][j+k]-occ[t[i]][j]);
			printf("%d\n",ans+=len[i]);
		}
	}
	return 0;
}