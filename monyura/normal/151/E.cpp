#pragma comment(linker,"/STACK:128000000")
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
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);

ll INF=1e18;

struct node
{
	int x,y;
	ll sum;
	ll mx,mn,res;
	node *left,*right;
	void init(int x0,int y0,ll s)
	{
		x=x0;
		y=y0;
		sum=s;
		left=right=0;
		mn=mx=sum;
		res=0;
	}
} BUFF[150150];
int BUFFcnt=0;

void recalc(node *v)
{
	if (v==0) return;
	v->mn=v->mx=v->sum;
	v->res=0;
	if (v->left)
	{
		if (v->right)
			movmax(v->res,v->right->mx - v->left->mn);
			//v->res=max(v->res, v->right->mx - v->left->mn);
		movmax(v->res,v->sum-v->left->mn);
		//v->res=max(v->res,v->sum - v->left->mn);
		movmax(v->res,v->left->res);
		//v->res=max(v->res,v->left->res);
		movmax(v->mx,v->left->mx);
		//v->mx=max(v->mx,v->left->mx);
		movmin(v->mn,v->left->mn);
		//v->mn=min(v->mn,v->left->mn);
	}
	if (v->right)
	{
		movmax(v->res,v->right->mx - v->sum);
		//v->res=max(v->res,v->right->mx - v->sum);
		movmax(v->res,v->right->res);
		//v->res=max(v->res,v->right->res);
		movmax(v->mx,v->right->mx);
		//v->mx=max(v->mx,v->right->mx);
		movmin(v->mn,v->right->mn);
		//v->mn=min(v->mn,v->right->mn);
	}
}

node* merge(node *L,node *R)
{
	if (L==0) return R;
	if (R==0) return L;
	if (L->y > R->y)
	{
		L->right=merge(L->right,R);
		recalc(L);
		return L;
	}
	R->left=merge(L,R->left);
	recalc(R);
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
		L=v;
		recalc(L);
		return;
	}
	split(v->left,L,v->left,x);
	R=v;
	recalc(R);
}

node* Add(node* v,int x,int y,ll s)
{
	node *L=0,*R=0,*added=&BUFF[BUFFcnt++];
	added->init(x,y,s);
	split(v,L,R,x);
	L=merge(L,added);
	return merge(L,R);
}

int main()
{
	int n,m,c;
	cin>>n>>m>>c;
	int X[200000];
	rep(i,0,n)
		scanf("%d",X+i);
	int P[200000];
	rep(i,0,n-1)
		scanf("%d",P+i);
	ll S[150001]={0};
	vector<int> St[150001];
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		St[b].push_back(a);
	}
	ll res=0;
	node *L=0,*R=0,*T=0;
	ll PS[150150]={0};
	rep(i,1,n)
		PS[i]=PS[i-1]+P[i-1];
	rep(i,0,n)
	{
		ll curr=100LL*X[i]-2LL*PS[i]*c;
		T=Add(T,i,rand(),curr);
		rep(j,0,St[i].size())
		{
			split(T,L,R,St[i][j]);
			ll mx=0;
			if (R) mx=R->res;
			res+=mx;
			T=merge(L,R);
		}
	}
	printf("%.8lf\n",res/200.0);
	return 0;
} 

/*
10000000000000

*/