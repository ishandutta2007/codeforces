#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;
const int MaxK=6;
const int MOD=1000000007;

int n,m;
int a[MaxN];
ll s[MaxN][MaxK];

ll C[MaxK][MaxK];

ll power(ll x,ll y)
{
	if (!y) return 1;
	ll t=power(x,y>>1);
	t=t*t%MOD;
	if (y&1) t=t*x%MOD;
	return t;
}

struct node
{
	node *Lc,*Rc;
	int L,R,m;
	ll v[MaxK];
	int p;
	node () {}
	node (int x,int y)
	{
		L=x;
		R=y;
		m=(L+R)>>1;
		p=-1;
	}
};

struct segment_tree
{
	node *root;
	void paint(node *it,int k)
	{
		it->p=k;
		for (int i=0;i<MaxK;++i)
			it->v[i]=k*(s[it->R][i]-s[it->L-1][i])%MOD;
	}
	void clear(node *it)
	{
		if (it->p==-1) return;
		paint(it->Lc,it->p);
		paint(it->Rc,it->p);
		it->p=-1;
	}
	void update(node *it)
	{
		for (int i=0;i<MaxK;++i)
			it->v[i]=(it->Lc->v[i]+it->Rc->v[i])%MOD;
	}
	node *build(int L,int R)
	{
		node *it=new node(L,R);
		if (L<R)
		{
			it->Lc=build(L,it->m);
			it->Rc=build(it->m+1,R);
			update(it);
		}
		else
		{
			for (int i=0;i<MaxK;++i)
				it->v[i]=a[L]*power(L,i)%MOD;
		}
		return it;
	}
	void build(int n)
	{
		root=build(1,n);
	}
	void draw(node *it,int x,int y,int k)
	{
		if (it->L==x&&it->R==y)
		{
			paint(it,k);
			return;
		}
		clear(it);
		if (y<=it->m)
			draw(it->Lc,x,y,k);
		else if (x>it->m)
			draw(it->Rc,x,y,k);
		else
		{
			draw(it->Lc,x,it->m,k);
			draw(it->Rc,it->m+1,y,k);
		}
		update(it);
	}
	void draw(int x,int y,int k)
	{
		draw(root,x,y,k);
	}
	ll calc(node *it,int x,int y,int k)
	{
		if (it->L==x&&it->R==y)
			return it->v[k];
		clear(it);
		if (y<=it->m)
			return calc(it->Lc,x,y,k);
		if (x>it->m)
			return calc(it->Rc,x,y,k);
		return (calc(it->Lc,x,it->m,k)+calc(it->Rc,it->m+1,y,k))%MOD;
	}
	void solve(int l,int r,int k)
	{
		ll ans=0;
		ll t=1;
		for (int i=0;i<=k;++i)
		{
			ans+=calc(root,l,r,k-i)*C[k][i]%MOD*t%MOD;
			t=t*(1-l)%MOD;
		}
		ans=(ans%MOD+MOD)%MOD;
		printf("%d\n",(int)ans);
	}
}T;

void init()
{
	cin>>n>>m;
	for (int i=0;i<MaxK;++i)
		C[i][0]=1;
	for (int i=1;i<MaxK;++i)
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		for (int j=0;j<MaxK;++j)
			s[i][j]=(s[i-1][j]+power(i,j))%MOD;
	}
	T.build(n);
}

void work()
{
	while (m--)
	{
		char s[4];
		int x,y,k;
		scanf("%s%d%d%d",s,&x,&y,&k);
		if (s[0]=='=')
			T.draw(x,y,k);
		else
			T.solve(x,y,k);
	}
}

int main()
{
	init();
	work();
	return 0;
}