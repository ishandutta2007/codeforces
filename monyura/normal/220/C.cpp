#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

typedef pair<double,double> pdd;

struct node
{
	int x,y;
	int add;
	int val;
	int mn;
	node *left,*right;
	void init(int x0,int y0,int val0)
	{
		left=right=0;
		add=0;
		x=x0;
		y=y0;
		val=val0;
		mn=val;
	}
} NODE_BUFF[400200];
int node_cnt=0;

void recalc(node *v)
{
	if (v==0) return;
	v->mn=v->val + v->add;
	if (v->left && v->left->mn + v->left->add < v->mn)
	{
		v->mn=v->left->mn + v->left->add;
	}
	if (v->right && v->right->mn + v->right->add < v->mn)
	{
		v->mn = v->right->mn + v->right->add;
	}
}

void push(node *v)
{
	if (v==0) return;
	v->val+=v->add;
	if (v->left)
		v->left->add+=v->add;
	if (v->right)
		v->right->add+=v->add;
	v->add=0;
}

node *merge(node *L,node *R)
{
	if (L==0) return R;
	if (R==0) return L;
	if (L->y > R->y)
	{
		push(L);
		L->right=merge(L->right,R);
		recalc(L);
		return L;
	}
	push(R);
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
	push(v);
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
	return;
}

node *Add(node *v,int x,int y,int val)
{
	node *L,*R,*added=NODE_BUFF+node_cnt++;
	added->init(x,y,val);
	split(v,L,R,x);
	L=merge(L,added);
	return merge(L,R);
}

node *remove(node *v,int x)
{
	node *L,*R,*del;
	split(v,L,R,x);
	split(R,del,R,x+1);
	return merge(L,R);
}

//void remove(node* &T,node*v)
//{
//	push(v);
//	if (v->from==0)
//	{
//		T=merge(v->left,v->right);
//		recalc(T);
//		return;
//	}
//	if (v->from->left==v)
//	{
//		v->from->left=merge(v->left,v->right);
//	}
//	else
//	{
//		v->from->right=merge(v->left,v->right);
//	}
//	v=v->from;
//	while (v)
//	{
//		recalc(v);
//		v=v->from;
//	}
//}

bool find(node *v,int x)
{
	if (v==0) return false;
	if (v->x==x) return true;
	if (v->x <x )
		return find(v->right,x);
	return find(v->left,x);
}

int fromBeg[100100];
int diff[100100];

int getMin(node *v)
{
	if (v==0)
		return 2e9;
	return v->mn + v->add;
}

void check(int *A,int *B,int n,vector<int> vec)
{
	int res=0;
	int pos[2000];
	rep(i,0,n)
		printf("%d ",A[i]);
	putchar('\n');
	rep(i,0,n)
		printf("%d ",B[i]);
	putchar('\n');
	rep(i,0,n)
	{
		int res=2e9;
		rep(j,0,n)
			pos[A[j]]=j;
		rep(j,0,n)
			res=min(res,abs(j-pos[B[j]]));
		if (res!=vec[i])
		{
			printf("FAIL real = %d find = %d\n",res,vec[i]);
		}
		rotate(B,B+1,B+n);
	}
}

void run()
{
	srand(time(0));
	int n;
	cin>>n;
	int A[100100];
	int B[100100];
	rep(i,0,n)
		scanf("%d",A+i);
	rep(i,0,n)
		scanf("%d",B+i);
	/*rep(i,0,n)
		B[i]=A[i]=i+1;
	random_shuffle(A,A+n);
	random_shuffle(B,B+n);*/
	rep(i,0,n)
	{
		fromBeg[A[i]]=i;
	}
	node *dA=0,*dB=0;
	vector<pii> events[100100];
	rep(i,0,n)
	{
		diff[B[i]]=i-fromBeg[B[i]];
		if (diff[B[i]]>=0)
		{
			dA=Add(dA,B[i],rand(),diff[B[i]]);
		}
		else
		{
			dB=Add(dB,B[i],rand(),abs(diff[B[i]]));
		}
		events[(diff[B[i]]+n)%n].push_back(pii(B[i],1));
		events[i].push_back(pii(B[i],n-1-fromBeg[B[i]]));
	}
	//vector<int> vec;
	//vec.resize(n);
	rep(i,0,n)
	{
		int res=min(getMin(dA),getMin(dB));
		//vec[i]=res;
		printf("%d\n",res);
		if (dA)
			dA->add--;
		if (dB)
			dB->add++;
		rep(j,0,events[i].size())
		{
			int x=events[i][j].first;
			int newVal=events[i][j].second;
			if (find(dB,x))
			{
				dB=remove(dB,x);
				dA=Add(dA,x,rand(),newVal);
			}
			else
			{
				dA=remove(dA,x);
				dB=Add(dB,x,rand(),newVal);
			}
		}
	}
	//check(A,B,n,vec);
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/