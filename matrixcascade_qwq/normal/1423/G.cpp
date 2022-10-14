//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
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

void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}const int maxn=2e5+10;
struct bit
{
    int c[maxn];
    int lowbit(int x){return x&(-x);}
    void upd(int x,int y=1){for(;x<=n;x+=lowbit(x))c[x]+=y;}
    int qry(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
    int operator[](int x) {return qry(x);}
}b,c;
#define itt set<node>::iterator
#define pir pair<long long,long long>
struct node{
	int l,r;
	mutable  int v;
	node (int ll,int rr=-1,int vv=0): l(ll),r(rr),v(vv){	}
	bool operator < (const node &u)const
	{
		return l<u.l;
	}
};

set<node>se;
set<node>s[maxn];
int a[maxn];
int tot=0;
unordered_map<int,int>lsh;
itt sp(int op)
{
	itt it=se.lower_bound(node(op));
	if(it!=se.end()&&it->l==op) return it;
	it--;
	int ll=it->l,rr=it->r,vv=it->v;
	se.erase(it);
	se.insert(node(ll,op-1,vv));
	s[vv].erase(node(ll,rr));
	s[vv].insert(node(ll,op-1));
	s[vv].insert(node(op,rr));
	return se.insert(node(op,rr,vv)).first;
}

int ans=0;
void ers(node x)
{
	int v=x.v;
	auto p=*(s[v].upper_bound(x.l));
	auto q=*(--s[v].lower_bound(x.l));
	int len1=(p.l-q.r-1);
	int len2=(p.l-x.r-1);
	int len3=(x.l-q.r-1);
	if(len1)b.upd(len1,1);
	if(len2)b.upd(len2,-1);
	if(len3)b.upd(len3,-1);
	
	if(len1)c.upd(len1,len1);
	if(len2)c.upd(len2,-1*len2);
	if(len3)c.upd(len3,-1*len3);
	s[v].erase(x);
	se.erase(x);
}
void ist(node x)
{
	int v=x.v;
	auto p=*(s[v].upper_bound(x.l));
	auto q=*(--s[v].lower_bound(x.l));
	
	int len1=(p.l-q.r-1);
	int len2=(p.l-x.r-1);
	int len3=(x.l-q.r-1);
	if(len1)b.upd(len1,-1);
	if(len2)b.upd(len2,1);
	if(len3)b.upd(len3,1);
//	cout<<len2<<" "<<len3;edl;
//	cout<<len1<<"qwdqwfq";edl;
	if(len1)c.upd(len1,-1*len1);
	if(len2)c.upd(len2,len2);
	if(len3)c.upd(len3,len3);
	s[v].insert(x);
	se.insert(x);
}
void ass(int ll,int rr,int vv)
{
	vector<itt>v;
	itt ir=sp(rr+1),il=sp(ll);
	while(il!=ir)
	{
		ers(*(il++));
	}
	ist(node(ll,rr,vv));
}

signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		upn
		{
			rd(a[i]);
		}
		up_(n+m)
		{
			s[i].insert(node(0,0));s[i].insert(node(n+1,n+1));
			b.upd(n,1);c.upd(n,n);
		}
	//	cout<<c[n];edl;
	//	cout<<b[5]-b[4];edl;
		upn
		{
			if(lsh.find(a[i])==lsh.end())
			{
				lsh[a[i]]=++tot;
			}
			int col=lsh[a[i]];
			ist(node(i,i,col));
		}
/*
5 4 3
25 8 6
5 2 2
*/
	//	cout<<b[4]-b[3];edl;
	//	cout<<c[4]-c[3];edl;	
		up_(m)
		{
			int opt,l,r,t;
			rd(opt);
			if(opt==2)
			{
				rd(t);
				int ans=(n-t+1)*(n+m);//cout<<ans;edl;
			//	cout<<(c[n]-c[t-1]);edl;
				ans-=((c[n]-c[t-1])-(b[n]-b[t-1])*(t-1));
				opd(ans);edl;
			}
			else
			{
				rd(l);rd(r);rd(t);
				int col;
				if(lsh.find(t)==lsh.end())lsh[t]=++tot;
				col=lsh[t];
				ass(l,r,col);
			}
		}
	}
}
/*
5 5
5 5 3 4 5
2 4
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/




///