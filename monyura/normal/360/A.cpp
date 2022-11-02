#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif


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


void run()
{
	int n,m;
	cin>>n>>m;
	int A[6000];
	rep(i,0,n)
		A[i] = 1e9;
	int Add[6000]={0};
	typedef pair<pii,pii> piii;
	int T[6000],L[6000],R[6000],X[6000];
	rep(q,0,m)
	{
		int t,a,b,x;
		scanf("%d%d%d%d",&t,&a,&b,&x);
		--a;--b;
		T[q] = t;
		L[q] = a;
		R[q] = b;
		X[q] = x;
		if (t==1)
		{
			rep(i,a,b+1)
				Add[i] += x;
		}
		else
		{
			rep(i,a,b+1)
				A[i] = min(A[i],x - Add[i]);
		}
	}
	int Ans[6000]={0};
	memcpy(Ans,A,sizeof(int)*n);
	rep(i,0,m)
	{
		if (T[i] == 1)
			rep(j,L[i],R[i]+1)
				A[j] += X[i];
		else
		{
			int mx = A[L[i]];
			rep(j,L[i],R[i]+1)
				mx = max(mx,A[j]);
			if (mx != X[i])
			{
				puts("NO");
				return;
			}
		}
				
	}
	puts("YES");
	rep(i,0,n)
		printf("%d ",Ans[i]);
	puts("");
}

//#define prob "kids"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}