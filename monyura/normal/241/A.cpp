#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
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
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

const int SZ=61000;
const int DO_SZ=4*SZ;

struct node
{
	int x;
	int y;
	int b;
	int val;
	int sum;
	int maxPref;
	node *left,*right;
	void init(int x0,int b0,int v0,int y0)
	{
		x=x0;
		y=y0;
		b=b0;
		val=v0;
		maxPref=sum=(b-x+1)*val;
		left=right=0;
	}
} BUFF[400200];
int B_CNT=0;

int getSum(node *v)
{
	return v?v->sum:0;
}

int getMaxPref(node *v)
{
	return v?v->maxPref : 0;
}

void recalc(node *v)
{
	if (v==0) return;
	v->sum = (v->b - v->x + 1)*v->val + getSum(v->left) + getSum(v->right);
	v->maxPref = getSum(v->left) + max((v->b - v-> x + 1)*v->val,0);
	v->maxPref = max(v->maxPref,getSum(v->left) + (v->b - v->x + 1)*v->val + getMaxPref(v->right));
	v->maxPref = max(v->maxPref,getMaxPref(v->left));
}

node *merge(node *L,node *R)
{
	if (L==0)
		return R;
	if (R==0)
		return L;
	if (L->y > R->y)
	{
		L->right = merge(L->right,R);
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
		R=L=0;
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

void add(node* &v,int x,int b,int val,int y)
{
	node *L,*R,*added=BUFF+B_CNT++;
	added->init(x,b,val,y);
	split(v,L,R,x);
	L=merge(L,added);
	v=merge(L,R);
}

void remove(node *&v,int x)
{
	node *L,*R,*del;
	split(v,L,R,x);
	split(R,del,R,x+1);
	v=merge(L,R);
}

node *getLast(node *v)
{
	if (v==0) return v;
	return v->right ? getLast(v->right) : v;
}

void proc(node* &v,int x,int b,int d)
{
	node *L,*R,*M;
	split(v,L,R,x);
	split(R,M,R,b+1);
	node *lst=getLast(M);
	if (lst!=0 && lst->b >b)
	{
		add(R,b+1,lst->b,lst->val,lst->y);
	}
	lst=getLast(L);
	if (lst!=0 && lst->b >=x)
	{
		remove(L,lst->x);
		add(L,lst->x,x-1,lst->val,lst->y);
		if (lst->b > b)
			add(R,b+1,lst->b,lst->val,rand());
	}
	node *added=BUFF+B_CNT++;
	added->init(x,b,d,rand());
	L=merge(L,added);
	v=merge(L,R);
}

void recalcLast(node *v)
{
	if (v==0) return;
	recalcLast(v->right);
	recalc(v);
}

int calc(node *&v,int x)
{
	node *L,*R;
	split(v,L,R,x+1);
	node *lst=getLast(L);
	int res=getMaxPref(L);
	if (lst && lst->b > x)
	{
		int was=lst->b;
		lst->b = x;
		recalcLast(L);
		res=getMaxPref(L);
		lst->b = was;
		recalcLast(L);
	}
	v=merge(L,R);
	return res;
}

int TMP[100100];

int getBruteRes(int h,int n)
{
	int res=0;
	int s=0;
	rep(i,1,n+1)
	{
		s+=TMP[i];
		if (s<=h)
			++res;
		else
			break;
	}
	return res;
}

void update(int a,int b,int val)
{
	rep(i,a,b+1)
		TMP[i]=val;
}


void run()
{
	int m,k;
	cin>>m>>k;
	int D[1002]={0};
	int S[1002]={0};
	rep(i,0,m)
		scanf("%d",D+i);
	rep(i,0,m)
		scanf("%d",S+i);
	int mx=0;
	int curr=0;
	int res=0;
	rep(i,0,m)
	{
		mx=max(mx,S[i]);
		curr+=S[i];
		if (D[i]>curr)
		{
			int left=(D[i]-curr);
			int cnt=left/mx + (left%mx!=0);
			res+=k*cnt;
			curr+=cnt*mx;
		}
		res+=D[i];
		curr-=D[i];
	}
	cout<<res<<endl;
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*


11
I 1 10 10
Q 10
Q 20
Q 21
Q 29
Q 31
I 1 10 -1
Q 0
I 1 3 1
I 4 9 1
I 10 10 1
I 2 5 1
Q 1
Q 2
Q 3
Q 4
Q 5
Q 6
Q 7
Q 8
Q 9
Q 10
I 6 10 -1
I 11 11 8
Q 1
Q 2
Q 3
Q 4
Q 5
Q 6
Q 7
Q 8
Q 9
Q 10
E
*/