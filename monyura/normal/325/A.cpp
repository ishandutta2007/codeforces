#pragma comment(linker,"/STACK:650000000")
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


const int INF = 40000;
void run()
{
	int n;
	cin>>n;
	int mnx = INF ,mxx = -INF,mny = INF,mxy = -INF;
	ll sq = 0;
	rep(i,0,n)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		mnx = min(x1,mnx);
		mxx = max(x2,mxx);
		mny = min(y1,mny);
		mxy = max(y2,mxy);
		sq += (x2-x1)*ll(y2-y1);
	}
	ll a = mxx-mnx, b = mxy-mny;
	puts (a==b && a*b==sq ? "YES":"NO");
}

//#define problem "party"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(problem".in","r",stdin);
	//freopen(problem".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}