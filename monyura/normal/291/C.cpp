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

void run()
{
	int n,k;
	ui P[100100];
	cin>>n>>k;
	rep(i,0,n)
	{
		int A[4];
		scanf("%d.%d.%d.%d",A,A+1,A+2,A+3);
		P[i] = 0;
		rep(j,0,4)
			P[i] = (P[i]<<8)|A[j];
	}
	ui Net[100100];
	for(int res=31;res>0;--res)
	{
		ui mask = ~((1LL<<res)-1);
		rep(i,0,n)
			Net[i]=P[i]&mask;
		sort(Net,Net+n);
		int cnt = unique(Net,Net+n) - Net;
		if (cnt==k)
		{
			int A[4];
			for (int i=3;i>=0;--i,mask>>=8)
				A[i] = mask & 0xFF;
			printf("%d.%d.%d.%d\n",A[0],A[1],A[2],A[3]);
			return;
		}
	}
	puts("-1");
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