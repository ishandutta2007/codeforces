#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
#define pb push_back
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}

#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
const int maxn=(1<<12)+10;
int dis[55][maxn];
pii pre[55][maxn];
string s[11];
unordered_map<char,int>mp;
unordered_map<int,char>mmp;
int p1[11][55],p2[11][55];
void print(pii nw)
{
	if(nw.fi==-1)return;
	print(pre[nw.fi][nw.se]);
//	cout<<nw.fi<<" ";
	cout<<mmp[nw.fi];
//	cout<<dis[nw.fi][nw.se]<<" ";
}
void bfs()
{
	queue<pii>q;
	memset(dis,0,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	up(i,0,51)
	{
		up(j,0,(1<<n)-1)
		{
			int fl=1;
			up(t,0,n-1)
			{
				if(j&(1<<t))fl&=((p1[t][i]!=-1)&&(p2[t][i]!=-1));
				else fl&=(p1[t][i]!=-1);
			}
			if(fl)q.push(mkp(i,j));
		}
	}
	int anss=0;pii as=mkp(-1,-1);
	while(!q.empty())
	{
		pii nw=q.front();q.pop();
		int x=nw.fi,msk=nw.se;
	//	cout<<x<<" "<<msk;edl;
		if(dis[x][msk]==0)dis[x][msk]=1;
		if(dis[x][msk]>anss)
		{
	//		cout<<anss<<" qws ";
			anss=dis[x][msk];as=mkp(x,msk);
	//		cout<<dis[x][msk]<<" "<<x<<" "<<msk;edl;
		}
		up(j,0,51)
		{
			int fl=1;
			int ma=0;
			up(i,0,n-1)
			{
				int pos;
				if(msk&(1<<i))pos=p2[i][x];
				else pos=p1[i][x];
			//	cout<<p2[i][j];edl;
				if(p1[i][j]>pos);
				else if(p2[i][j]>pos)ma|=(1<<i);
				else fl=0;
			}
			if(!fl)continue;
			if(dis[x][msk]+1>dis[j][ma])
			{
				dis[j][ma]=dis[x][msk]+1;
				pre[j][ma]=mkp(x,msk);
				q.push(mkp(j,ma));
			}
		}
	}
	opd(anss);edl;print(as);edl;
}
signed main()
{
	up(i,'a','z')mp[i]=i-'a';
	up(i,'A','Z')mp[i]=i-'A'+26;
	fp mp pf mmp[to.se]=to.fi;
	int T=read();
	while(T--)
	{
		rdn;
		up(i,0,n-1) cin>>s[i];
		memset(p1,-1,sizeof(p1));
		memset(p2,-1,sizeof(p2));
		up(i,0,n-1)
		{
			up(j,0,s[i].size()-1)
			{
			//	cout<<s[i][j]<<" "<<mp[s[i][j]];edl;
				if(p1[i][mp[s[i][j]]]==-1)p1[i][mp[s[i][j]]]=j;
				else p2[i][mp[s[i][j]]]=j;
			}
		}
//		cout<<p1[0][26];edl;
		bfs();
		
	}
}
/*
1
2
codeforces
technocup
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/