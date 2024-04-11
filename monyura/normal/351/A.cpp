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

inline int up(int val)
{
	if (val == 0)
		return 0;
	return 1000 - val;
}

inline int down(int val)
{
	if (val==0)
		return 0;
	return val;
}

void run()
{
	int n;
	cin>>n;
	int A[2001];
	int zero = 0;
	int sum = 0;
	rep(i,0,2*n)
	{
		int a,b;
		scanf("%d.%d",&a,&b);
		A[i] = b;
		sum += A[i];
		if (A[i]==0)
			++zero;
	}
	zero = min(zero,n);
	int best = 1e9;
	rep(i,n-zero, n+1)
	{
		best = min(best, abs(1000 * i - sum));
	}
	printf("%d.%.3d",best/1000,best%1000);
	/*const int INF = 1e9;
	int D[2002][2002];
	rep(i,0,2002)
		rep(j,0,2002)
			D[i][j] = INF;
	D[0][0] = 0;
	rep(i,1,2*n+1)
	{
		int val = A[i-1];
		D[i][0] = D[i-1][0] - up(val);
		rep(j,1,i+1)
		{
			int cUp = D[i-1][j] - up(val);
			int cDwn = D[i-1][j-1] + down(val);
			if (abs(cUp) < abs(
		}
	}*/
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