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

ll gcd(ll a,ll b)
{
	while (b)
	{
		ll c = b;
		b = a % b;
		a = c;
	}
	return a;
}

void run()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	ll kNum = b, kDenom = d;
	if (a * d < c * b)
	{
		kNum = a;
		kDenom = c;
	}
	ll rNum = a*b*kDenom*kDenom - c*d*kNum*kNum;
	ll rDenom = a*b*kDenom*kDenom;
	ll g = gcd(rNum, rDenom);
	cout<<rNum/g<<'/'<<rDenom/g<<endl;
}

//#define prob "fibsubseq"
int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen(prob".in","r",stdin);
    //freopen(prob".out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}