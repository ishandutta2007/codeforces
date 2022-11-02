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

const double PI = acos(-1.0);

ll D[501][501]={0};
void run()
{
    int n;
	cin>>n;
	rep(i,0,n)
		rep(j,0,n)
		{
			int a;
			scanf("%d",&a);
			D[i][j] = a;
		}
	int P[501];
	rep(i,0,n)
	{
		scanf("%d",P+i);
		--P[i];
	}
	int Rev[501];
	rep(i,0,n)
		Rev[P[i]] = i;
	ll Res[501]={0};
	for (int k=n-1;k>=0;k--)
	{
		ll res = 0;
		int v = P[k];
		rep(i,0,n)
			rep(j,0,n)
				D[i][j] = min(D[i][j],D[i][v] + D[v][j]);
		rep(i,0,n)
			rep(j,0,n)
				if (Rev[i]>=k && Rev[j]>=k)
					res+=D[i][j];
		Res[k] = res;
	}
	rep(i,0,n)
		printf("%I64d ",Res[i]);
	puts("");
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