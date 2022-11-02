

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
ll D[100100][2][2]={0};
void run()
{
	int mod = 1e9+7;
	D[0][0][0] = 1;
	char A[100100],B[100100];
	int n;
	scanf("%d",&n);
	scanf(" %s %s",A,B);
	rep(i,0,n)
	{
		int fra = 0,toa=9;
		int frb = 0,tob=9;
		if (A[i]!='?') fra=toa=A[i]-'0';
		if (B[i]!='?') frb=tob=B[i]-'0';
		rep(j,0,2)
			rep(k,0,2)
			{
				D[i][j][k]%=mod;
				rep(a,fra,toa+1)
					rep(b,frb,tob+1)
						D[i+1][j|(a>b)][k|(b>a)]+=D[i][j][k];
			}
	}
	int res = D[n][1][1] % mod;
	printf("%d\n",res);
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