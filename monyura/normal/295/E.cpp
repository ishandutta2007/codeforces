

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);

struct node
{
	int x;
	int y;
	int cnt;
	ll sum;
	ll ans;
	node *left, * right;
	void init(int x0,int y0)
	{
		x = x0;
		y = y0;
		sum = x;
		ans = 0;
		cnt = 1;
		left = right = 0;
	}
} BUFF[300300];
int b_pos=0;

inline ll getCnt(node *v)
{
	return v ? v->cnt : 0;
}

inline ll getSum(node *v)
{
	return v ? v->sum : 0;
}

inline ll getAns(node *v)
{
	return v? v->ans : 0;
}

inline void recalc(node *v)
{
	if (v==0) return;
	v->cnt = 1 + getCnt(v->left) + getCnt(v->right);
	v->sum = v->x + getSum(v->left) + getSum(v->right);
	v->ans = getAns(v->left) + getAns(v->right) 
		+ (getCnt(v->left) - getCnt(v->right)) * v->x 
		+ (1 + getCnt(v->left)) * getSum(v->right) - (1+getCnt(v->right))*getSum(v->left);
}

node *merge(node *L,node *R)
{
	if (L==0)
		return R;
	if (R==0)
		return L;
	if (L->y > R->y)
	{
		L->right = merge(L->right, R);
		recalc(L);
		return L;
	}
	R->left = merge(L,R->left);
	recalc(R);
	return R;
}

void split(node* v, node* &L,node* &R,int x)
{
	if (v==0)
	{
		L=R=0;
		return;
	}
	if (v->x < x)
	{
		split(v->right,v->right,R,x);
		recalc(v);
		L=v;
		return;
	}
	split(v->left,L,v->left,x);
	recalc(v);
	R=v;
}

void add(node* &v,int x,int y)
{
	node *L,*R,*added = BUFF + b_pos++;
	added->init(x,y);
	split(v,L,R,x);
	L = merge(L,added);
	v = merge(L,R);
}

void remove(node* &v,int x)
{
	node *L,*R,*del;
	split(v,L,R,x);
	split(R,del,R,x+1);
	v = merge(L,R);
}

void run()
{
	int X[100100];
	int n;
	scanf("%d",&n);
	node *T = 0;
	rep(i,0,n)
	{
		scanf("%d",X+i);
		add(T,X[i],rand());
	}
	int m;
	scanf("%d",&m);
	rep(i,0,m)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int p,d;
			scanf("%d%d",&p,&d);
			--p;
			remove(T,X[p]);
			X[p]+=d;
			add(T,X[p],rand());
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			node *L,*M,*R;
			split(T,L,R,l);
			split(R,M,R,r+1);
			ll res = getAns(M);
			L = merge(L,M);
			T = merge(L,R);
			printf("%I64d\n",res);
		}
	}
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf( "=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}