#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long 
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
using namespace std;
const int inf=1039714778;
const int mod=1e9+7;
const ll llinf=1LL*inf*inf;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
template <typename T> inline void chmin(T &x,const T &b) {x=min(x,b);}
template <typename T> inline void chmax(T &x,const T &b) {x=max(x,b);}
template <typename T> inline T mabs(const T &x) {return x<0?-x:x;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31) & mod;}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,const pair<T1,T2> &o)
{
	cout<<'('<<o.first<<','<<o.second<<')';
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,const vector<T> &v)
{
	int fst=1;
	cout<<'{';
	for(auto &x:v)
	{
		if(!fst) cout<<',';
		else fst=0;
		cout<<x;
	}
	cout<<'}';
	return cout;
}

template<typename T>
ostream & operator << (ostream &cout,const set<T> &s)
{
	vector<T> v;
	for(auto x:s) v.emplace_back(x);
	cout<<v;
	return cout;
}

template<typename T>
ostream & operator << (ostream &cout,const multiset<T> &s)
{
	vector<T> v;
	for(auto x:s) v.emplace_back(x);
	cout<<v;
	return cout;
}

namespace FastIO
{
    const int MaxBufSize=1024*1024;
    char buf[MaxBufSize+5];
    int cursor=MaxBufSize;
    inline char getchar()
    {
        if(cursor==MaxBufSize)
        {
            fread(buf,1,MaxBufSize,stdin);
            cursor=0;
        }
        return buf[cursor++];
    }
    inline ll getnum()
    {
        static ll res;
        static char c;
        static int mut;
        res=0;
        c=0;
        mut=1;
        while(!isdigit(c) && c!='-') c=getchar();
        if(c=='-')
        {
            mut=-1;
            c=getchar();
        }
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res*mut;
    }
} // namespace FastIO
using FastIO::getnum;

int n,m;
int dfn[400005],low[400005],stk[400005],top,T,tot;
int dp[800005][3];
int head[800005];
int nxt[1600005],val[1600005];
int cnt=1,cnt0=1;
int head0[400005],nxt0[1200005];
pii val0[1200005];

void insert(int &x,int v)
{
	nxt[cnt]=x;
	val[cnt]=v;
	x=cnt++;
}

void insert(int &x,pii v)
{
	nxt0[cnt0]=x;
	val0[cnt0]=v;
	x=cnt0++;
}

void tarjan(int x,int pid)
{
	dfn[x]=low[x]=T++;
	stk[top++]=x;
	for(int it=head0[x];it;it=nxt0[it])
	{
		pii o=val0[it];
		int u=o.first,id=o.second;
		if(id==pid) continue;
		if(dfn[u]==-1)
		{
			tarjan(u,id);
			chmin(low[x],low[u]);
			if(low[u]>dfn[x])
			{
				insert(head[x],u);
				insert(head[u],x);
				assert(top && stk[top-1]==u);
				top--;
			}
			else if(low[u]==dfn[x])
			{
				do
				{
					top--;
					insert(head[stk[top]],tot);
					insert(head[tot],stk[top]);
				}while(stk[top]!=u);
				insert(head[x],tot);
				insert(head[tot],x);
				tot++;
			}
		}
		else chmin(low[x],dfn[u]);
	}
}

void dfs(int x,int par=-1)
{
	for(int it=head[x];it;it=nxt[it])
	{
		int u=val[it];
		if(u==par) continue;
		dfs(u,x);
	}
	if(x>=n)
	{
		int s0=0,s1=inf,s11=inf,s2=inf;
		for(int it=head[x];it;it=nxt[it])
		{
			int u=val[it];
			if(u==par) continue;
			s2=min(s2+dp[u][0],s0+dp[u][2]);
			s11=min(s11+dp[u][0],s1+dp[u][1]);
			s1=min(s1+dp[u][0],s0+dp[u][1]);
			s0+=dp[u][0];
		}
		dp[x][0]=min({s0+1,s1+1,s2,s11});
		dp[x][1]=min({s0+2,s1+1,s2,s11+1});
		dp[x][2]=min({s0+3,s1+2,s2,s11+1});
	}
	else
	{
		int f[3],g[3];
		memset(f,0x3f,sizeof(f));f[0]=0;
		for(int it=head[x];it;it=nxt[it])
		{
			int u=val[it];
			if(u==par) continue;
			memset(g,0x3f,sizeof(g));
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int t=0;t<=min(i,j);t++)
					{
						if(i-t+j-t>2) continue;
						chmin(g[i-t+j-t],f[i]+dp[u][j]-t);
					}
				}
			}
			memcpy(f,g,sizeof(g));
		}
		chmin(f[1],f[0]+1);
		chmin(f[2],f[1]+1);
		chmin(f[1],f[2]);
		chmin(f[0],f[1]);
		memcpy(dp[x],f,sizeof(f));
	}
	if(par!=-1 && par<n && x<n) dp[x][0]=dp[x][2]=inf;
	// if(x==1) cout<<dp[x][0]<<' '<<dp[x][1]<<' '<<dp[x][2]<<endl;
}

int main()
{
// 	freopen("graph.in","r",stdin);
// 	freopen("graph.out","w",stdout);
	n=getnum();m=getnum();
	// int cnt=0;
	for(int i=0;i<m;i++)
	{
		int x=getnum(),y=getnum();
		x--;y--;
		insert(head0[x],mp(y,i));
		insert(head0[y],mp(x,i));
	}
	memset(dfn,-1,sizeof(dfn));
	tot=n;
	// double t=clock();
	// return 0;
	tarjan(0,-1);
	// cerr<<(clock()-t)/CLOCKS_PER_SEC<<endl;
	// cout<<tot<<endl;
	// for(int i=0;i<tot;i++) cout<<vec[i]<<' ';
	// cout<<endl;
	dfs(0);
	cout<<dp[0][0]<<' '<<m<<endl;
	return 0;
}