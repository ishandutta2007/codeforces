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

typedef long long int64;
typedef long double real;
typedef pair<int,int> pii;

#define X first
#define Y second

const int MaxN=100010;

int n;
pii p[MaxN];
int x[MaxN],y[MaxN];
int v[10],u[10],a[10];

int tot;
struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	vector<int> v;
}tree[MaxN*2],*root;

node *build(int L,int R)
{
	node *it=&tree[++tot];
	it->L=L;
	it->R=R;
	for (int i=L;i<=R;++i)
		it->v.push_back(p[i].Y);
	sort(it->v.begin(),it->v.end());
	if (L<R)
	{
		it->mid=(L+R)>>1;
		it->Lc=build(L,it->mid);
		it->Rc=build(it->mid+1,R);
	}
	return it;
}

int get(node *it,int x,int y)
{
	if (!it) return 0;
	if (p[it->L].X>x) return 0;
	if (p[it->R].X<=x)
		return upper_bound(it->v.begin(),it->v.end(),y)-it->v.begin();
	return get(it->Lc,x,y)+get(it->Rc,x,y);
}

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&p[i].X,&p[i].Y);
		x[i]=p[i].X;
		y[i]=p[i].Y;
	}
	sort(p+1,p+n+1);
	root=build(1,n);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	for (int i=1;i<=9;++i)
		cin>>v[i];
}

int flag,ax[3],ay[3];

void check()
{
	int sx[]={0,a[1]+a[4]+a[7],a[2]+a[5]+a[8],a[3]+a[6]+a[9]};
	int sy[]={0,a[7]+a[8]+a[9],a[4]+a[5]+a[6],a[1]+a[2]+a[3]};
	for (int i=1;i<=3;++i)
	{
		sx[i]+=sx[i-1];
		sy[i]+=sy[i-1];
	}
	int fx[3],fy[3];
	for (int i=1;i<=2;++i)
	{
		if (x[sx[i]+1]==x[sx[i]]) return;
		if (y[sy[i]+1]==y[sy[i]]) return;
		fx[i]=x[sx[i]];
		fy[i]=y[sy[i]];
	}
	if (get(root,fx[1],fy[1])!=a[7]) return;
	if (get(root,fx[1],fy[2])!=a[4]+a[7]) return;
	if (get(root,fx[2],fy[1])!=a[7]+a[8]) return;
	if (get(root,fx[2],fy[2])!=a[4]+a[5]+a[7]+a[8]) return;
	flag=1;
	ax[1]=fx[1];
	ax[2]=fx[2];
	ay[1]=fy[1];
	ay[2]=fy[2];
}

void DFS(int k)
{
	if (k==10)
	{
		check();
		return;
	}
	for (int i=1;i<=9;++i)
		if (!u[i])
		{
			u[i]=1;
			a[k]=v[i];
			DFS(k+1);
			u[i]=0;
		}
}

void work()
{
	DFS(1);
	if (!flag)
	{
		puts("-1");
		return;
	}
	printf("%lf %lf\n%lf %lf\n",ax[1]+.5,ax[2]+.5,ay[1]+.5,ay[2]+.5);
}

int main()
{
	init();
	work();
	return 0;
}