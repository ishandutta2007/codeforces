#pragma comment(linker,"/STACK:65000000")
#include <iostream>
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
#include <assert.h>


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
typedef vector<int> vi;

const double PI = acos(-1.0);

const int SZ = 100100;
int Add[4*SZ];

void update(int v,int l,int r,int ql,int qr,int pos)
{
	if (l==ql && r==qr)
	{
		Add[v] = pos;
		return;
	}
	int c=(l+r)>>1;
	if (Add[v]!=-1)
	{
		Add[2*v]=Add[v];
		Add[2*v+1]=Add[v]+c-l+1;
		Add[v]=-1;
	}
	
	if (qr<=c)
		update(2*v,l,c,ql,qr,pos);
	else if (ql>c)
		update(2*v+1,c+1,r,ql,qr,pos);
	else
	{
		update(2*v,l,c,ql,c,pos);
		update(2*v+1,c+1,r,c+1,qr,pos+c-ql+1);
	}
}

int A[SZ];
int B[SZ];
int get(int v,int l,int r,int pos)
{
	if (Add[v]!=-1)
		return A[Add[v]+pos-l];
	if (l==r)
		return B[pos];
	int c = (l+r)>>1;
	if (pos<=c)
		return get(2*v,l,c,pos);
	return get(2*v+1,c+1,r,pos);
}



void run()
{
	memset(Add,-1,sizeof(Add));
	int n,m;
	cin>>n>>m;
	rep(i,0,n)
		scanf("%d",A+i);
	rep(i,0,n)
		scanf("%d",B+i);
	rep(i,0,m)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			--x;--y;
			update(1,0,n-1,y,y+k-1,x);
		}
		else
		{
			int x;
			scanf("%d",&x);
			--x;
			int res = get(1,0,n-1,x);
			printf("%d\n",res);
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
	//freopen("path.in","r",stdin);
	//freopen("path.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*

*/