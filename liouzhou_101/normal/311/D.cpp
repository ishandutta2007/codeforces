#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
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
const int MOD=95542721;
const int LEN=48;

int n;
int a[MaxN];

struct node
{
	node *Lc,*Rc;
	int L,R,m;
	int p;
	int v[LEN];
	node (int x,int y)
	{
		L=x;
		R=y;
		m=(L+R)>>1;
		p=0;
		Lc=Rc=0;
		memset(v,0,sizeof(v));
	}
};

node *root;
int tmp[LEN];

int mod(int x,int MOD)
{
	while (x>=MOD) x-=MOD;
	return x;
}

void update(node *it)
{
	for (int i=0;i<LEN;++i)
		it->v[i]=mod(it->Lc->v[i]+it->Rc->v[i],MOD);
}

void clear(node *it)
{
	if (!it->p) return;
	memcpy(tmp,it->Lc->v,sizeof(tmp));
	for (int i=0;i<LEN;++i)
		it->Lc->v[i]=tmp[mod(i+it->p,LEN)];
	it->Lc->p=mod(it->Lc->p+it->p,LEN);
	memcpy(tmp,it->Rc->v,sizeof(tmp));
	for (int i=0;i<LEN;++i)
		it->Rc->v[i]=tmp[mod(i+it->p,LEN)];
	it->Rc->p=mod(it->Rc->p+it->p,LEN);
	it->p=0;
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
		int t=a[L];
		for (int i=0;i<LEN;++i)
		{
			it->v[i]=t;
			t=(ll)t*t%MOD*t%MOD;
		}
	}
	return it;
}

int query(node *it,int L,int R)
{
	if (it->L==L&&it->R==R)
		return it->v[0];
	clear(it);
	if (R<=it->m)
		return query(it->Lc,L,R);
	if (L>it->m)
		return query(it->Rc,L,R);
	return mod(query(it->Lc,L,it->m)+query(it->Rc,it->m+1,R),MOD);
}

void modify(node *it,int L,int R)
{
	if (it->L==L&&it->R==R)
	{
		it->p++;
		memcpy(tmp,it->v,sizeof(tmp));
		for (int i=0;i<LEN;++i)
			it->v[i]=tmp[mod(i+1,LEN)];
		return;
	}
	clear(it);
	if (R<=it->m)
		modify(it->Lc,L,R);
	else if (L>it->m)
		modify(it->Rc,L,R);
	else
	{
		modify(it->Lc,L,it->m);
		modify(it->Rc,it->m+1,R);
	}
	update(it);
}

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[i]%=MOD;
	}
	root=build(1,n);
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int flag,x,y;
		scanf("%d%d%d",&flag,&x,&y);
		if (flag==1)
			printf("%d\n",query(root,x,y));
		else
			modify(root,x,y);
	}
}

int main()
{
	init();
	work();
	return 0;
}