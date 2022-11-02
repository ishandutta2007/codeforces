#pragma comment(linker,"/STACK:64000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
//#define x first
//#define y second

const double PI=acos(-1.0);

struct node
{
	int x;
	int y;
	int b,ind;
	int maxb;
	node *left,*right;
	void init(int x0,int y0,int t0,int ind0)
	{
		left=right=0;
		x=x0;y=y0;
		maxb=b=t0;ind=ind0;
	}
} BUF[100100];
int BUFPOS=0;

void pereshet(node* v)
{
	v->maxb=v->b;
	if (v->left!=0 && v->left->maxb > v->maxb)
		v->maxb=v->left->maxb;
	if (v->right!=0 && v->right->maxb > v->maxb)
		v->maxb=v->right->maxb;
}

node* merge(node *L,node *R)
{
	if (L==0) return R;
	if (R==0) return L;
	if (L->y > R->y)
	{
		L->right=merge(L->right,R);
		pereshet(L);
		return L;
	}
	R->left=merge(L,R->left);
	pereshet(R);
	return R;
}

void split(node *v,node* &L,node* &R,int x)
{
	if (v==0)
	{
		L=R=0;
		return;
	}
	if (v->x < x)
	{
		split(v->right,v->right,R,x);
		pereshet(v);
		L=v;
		return;
	}
	split(v->left,L,v->left,x);
	pereshet(v);
	R=v;
}

node* add(node *v,int x,int y,int b,int ind)
{
	node *added=&BUF[BUFPOS++],*L=0,*R=0;
	added->init(x,y,b,ind);
	split(v,L,R,x);
	L=merge(L,added);
	return merge(L,R);
}

struct ent
{
	int l,r,t,ind;
} A[100100], P[100100];

bool operator<(const ent &a,const ent &b)
{
	return a.l<b.l;
}

inline int getMaxB(node *t)
{
	if (t==0) return -1;
	return t->maxb;
}

int bval;
int getAns(node *v)
{
	if (v==0) return -1;
	if (getMaxB(v->left)>=bval)
		return getAns(v->left);
	if (v->b>=bval)
		return v->ind+1;
	if (getMaxB(v->right)>=bval)
		return getAns(v->right);
	return -1;
}

int main()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,n)
	{
		scanf("%d%d%d",&A[i].l,&A[i].r,&A[i].t);
		A[i].ind=i;
	}
	rep(i,0,m)
	{
		scanf("%d%d%d",&P[i].l,&P[i].r,&P[i].t);
		P[i].ind=i;
	}
	sort(A,A+n);
	sort(P,P+m);
	int p1=0,p2=0;
	node *T=0,*L=0,*R=0;
	int Ans[100100];
	while (p2<m)
	{
		while (p1<n && A[p1].l<=P[p2].l) 
		{
			T=add(T,A[p1].t,rand(),A[p1].r,A[p1].ind);
			p1++;
		}
		while (p2<m && (p1<n && P[p2].l<A[p1].l || p1==n))
		{
			split(T,L,R,P[p2].t);
			bval=P[p2].r;
			Ans[P[p2].ind]=getAns(R);
			T=merge(L,R);
			p2++;
		}
	}
	rep(i,0,m)
		printf("%d ",Ans[i]);
	return 0;
} 

/*


*/