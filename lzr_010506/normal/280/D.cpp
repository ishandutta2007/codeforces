#include <bits/stdc++.h>
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
const int INF=1000000000;

int n;
int a[MaxN];

struct node
{
	node *Lc,*Rc;
	int L,R,m,s;
	int v[21],Lv[21],Rv[21],pv[21];
	int tv[21],tLv[21],tRv[21],tpv[21];
	node (int x,int y)
	{
		L=x;
		R=y;
		m=(L+R)>>1;
		s=min(20,(y-x+2)/2);
		Lc=Rc=0;
		memset(v,0,sizeof(v));
		memset(Lv,0,sizeof(Lv));
		memset(Rv,0,sizeof(Rv));
		memset(pv,0,sizeof(pv));
		memset(tv,0,sizeof(tv));
		memset(tLv,0,sizeof(tLv));
		memset(tRv,0,sizeof(tRv));
		memset(tpv,0,sizeof(tpv));
	}
};

int k;
node *root;

void update(node *it,node *Lc,node *Rc)
{
	int is=it->s,Ls=Lc->s,Rs=Rc->s;
	for (int i=1;i<=is;++i)
	{
		it->v[i]=0;
		it->Lv[i]=it->Rv[i]=it->pv[i]=-INF;
	}
	for (int i=1;i<=Ls;++i)
	{
		it->v[i]=max(it->v[i],Lc->v[i]);
		it->Lv[i]=max(it->Lv[i],Lc->Lv[i]);
	}
	for (int i=1;i<=Rs;++i)
	{
		it->v[i]=max(it->v[i],Rc->v[i]);
		it->Rv[i]=max(it->Rv[i],Rc->Rv[i]);
	}
	for (int i=1;i<=Ls;++i)
		for (int j=1;j<=Rs;++j)
		{
			if (i+j<=is)
			{
				it->v[i+j]=max(it->v[i+j],Lc->v[i]+Rc->v[j]);
				it->Lv[i+j]=max(it->Lv[i+j],Lc->Lv[i]+Rc->v[j]);
				it->Rv[i+j]=max(it->Rv[i+j],Lc->v[i]+Rc->Rv[j]);
				it->pv[i+j]=max(it->pv[i+j],Lc->Lv[i]+Rc->Rv[j]);
			}
			if (i+j-1<=is)
			{
				it->v[i+j-1]=max(it->v[i+j-1],Lc->Rv[i]+Rc->Lv[j]);
				it->Lv[i+j-1]=max(it->Lv[i+j-1],Lc->pv[i]+Rc->Lv[j]);
				it->Rv[i+j-1]=max(it->Rv[i+j-1],Lc->Rv[i]+Rc->pv[j]);
				it->pv[i+j-1]=max(it->pv[i+j-1],Lc->pv[i]+Rc->pv[j]);
			}
			else
				break;
		}
}

void tupdate(node *it,node *Lc,node *Rc)
{
	int is=k,Ls=min(Lc->s,k),Rs=min(Rc->s,k);
	for (int i=1;i<=is;++i)
		it->tv[i]=it->tLv[i]=it->tRv[i]=it->tpv[i]=0;
	for (int i=1;i<=Ls;++i)
	{
		it->tv[i]=max(it->tv[i],Lc->tv[i]);
		it->tLv[i]=max(it->tLv[i],Lc->tLv[i]);
	}
	for (int i=1;i<=Rs;++i)
	{
		it->tv[i]=max(it->tv[i],Rc->tv[i]);
		it->tRv[i]=max(it->tRv[i],Rc->tRv[i]);
	}
	for (int i=1;i<=Ls;++i)
		for (int j=1;j<=Rs;++j)
		{
			if (i+j<=is)
			{
				it->tv[i+j]=max(it->tv[i+j],Lc->tv[i]+Rc->tv[j]);
				it->tLv[i+j]=max(it->tLv[i+j],Lc->tLv[i]+Rc->tv[j]);
				it->tRv[i+j]=max(it->tRv[i+j],Lc->tv[i]+Rc->tRv[j]);
				it->tpv[i+j]=max(it->tpv[i+j],Lc->tLv[i]+Rc->tRv[j]);
			}
			if (i+j-1<=is)
			{
				it->tv[i+j-1]=max(it->tv[i+j-1],Lc->tRv[i]+Rc->tLv[j]);
				it->tLv[i+j-1]=max(it->tLv[i+j-1],Lc->tpv[i]+Rc->tLv[j]);
				it->tRv[i+j-1]=max(it->tRv[i+j-1],Lc->tRv[i]+Rc->tpv[j]);
				it->tpv[i+j-1]=max(it->tpv[i+j-1],Lc->tpv[i]+Rc->tpv[j]);
			}
			else
				break;
		}
}

node *build(int L,int R)
{
	node *it=new node(L,R);
	if (L==R)
		it->v[1]=it->Lv[1]=it->Rv[1]=it->pv[1]=a[L];
	else
	{
		it->Lc=build(L,it->m);
		it->Rc=build(it->m+1,R);
		update(it,it->Lc,it->Rc);
	}
	return it;
}

void change(node *it,int x,int p)
{
	if (it->L==it->R)
	{
		it->v[1]=it->Lv[1]=it->Rv[1]=it->pv[1]=p;
		return;
	}
	if (x<=it->m)
		change(it->Lc,x,p);
	else
		change(it->Rc,x,p);
	update(it,it->Lc,it->Rc);
}

void query(node *it,int L,int R)
{
	if (it->L==L&&it->R==R)
	{
		int is=k;
		for (int i=1;i<=is;++i)
		{
			it->tv[i]=it->v[i];
			it->tLv[i]=it->Lv[i];
			it->tRv[i]=it->Rv[i];
			it->tpv[i]=it->pv[i];
		}
		return;
	}
	if (R<=it->m)
	{
		query(it->Lc,L,R);
		int is=k;
		for (int i=1;i<=is;++i)
		{
			it->tv[i]=it->Lc->tv[i];
			it->tLv[i]=it->Lc->tLv[i];
			it->tRv[i]=it->Lc->tRv[i];
			it->tpv[i]=it->Lc->tpv[i];
		}
	}
	else if (L>it->m)
	{
		query(it->Rc,L,R);
		int is=k;
		for (int i=1;i<=is;++i)
		{
			it->tv[i]=it->Rc->tv[i];
			it->tLv[i]=it->Rc->tLv[i];
			it->tRv[i]=it->Rc->tRv[i];
			it->tpv[i]=it->Rc->tpv[i];
		}
	}
	else
	{
		query(it->Lc,L,it->m);
		query(it->Rc,it->m+1,R);
		tupdate(it,it->Lc,it->Rc);
	}
}

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	root=build(1,n);
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int flag;
		scanf("%d",&flag);
		if (!flag)
		{
			int x,v;
			scanf("%d%d",&x,&v);
			change(root,x,v);
		}
		else
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			::k=k;
			query(root,x,y);
			int ans=0;
			for (int i=1;i<=k;++i)
				ans=max(ans,root->tv[i]);
			printf("%d\n",ans);
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}