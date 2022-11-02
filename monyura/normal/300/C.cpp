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

const int mod = 1e9+7;

ll toPow(ll a,int b)
{
	ll res = 1;
	while (b)
	{
		if (b&1)
			res= (res*a) %mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}

void run()
{
	int a,b,n;
	cin>>a>>b>>n;
	ll C = 1, res = 0;
	rep(i,0,n+1)
	{
		int sum = i*a + (n-i)*b;
		bool ok = true;
		while (sum)
		{
			if (sum%10!=a && sum%10!=b)
				ok = false;
			sum/=10;
		}
		if (ok)
		{
 			res = (res+C) % mod;
		}
		C = C * toPow(i+1,mod-2) % mod * (n-i) % mod;
	}
	cout<<res<<endl;
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