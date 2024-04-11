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

void run()
{
	int t;
	cin>>t;
	const int mod = 7340033;
	ll D[1002][31]={0};
	ll Pr[1002][31]={0};
	D[0][0] = 1;
	Pr[0][0] = 1;
	rep(deep,1,31)
	{
		D[0][deep]=1;
		rep(k,0,1002)
		{
			rep(a,0,k)
				D[k][deep] += Pr[a][deep-1]*Pr[k-a-1][deep-1] % mod;
			D[k][deep]%=mod;
		}
		rep(k,0,1002)
		{
			rep(a,0,k+1)
				Pr[k][deep] += D[a][deep]*D[k-a][deep] % mod;
			Pr[k][deep] %= mod;
		}
	}
	rep(i,0,t)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int deep=0;
		while ((n&1))
		{
			++deep;
			n>>=1;
		}
		if (n==0) --deep;
		int res = D[k][deep];
		printf("%d\n",res);
	}
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(name".in","r",stdin);
	//freopen(name".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/