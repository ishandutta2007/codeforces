#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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

ll x,y;

bool cmp(const pll &a,const pll &b)
{
	ll val1 = mabs(x*a.second - y*a.first);
	ll val2 = mabs(x*b.second - y*b.first);
	if (val1*b.second!=val2*a.second)
		return val1*b.second<val2*a.second;
	if (a.second!=b.second)
		return a.second<b.second;
	return a.first<b.first;
}
pll getBest(const pll &a,const pll &b)
{
	return cmp(a,b) ? a : b;
}

void run()
{
	int n;
	cin>>x>>y>>n;
	pll res(1,1);
	ll val = 1e15;
	rep(b,1,n+1)
	{
		ll a = x*b/y;
		res = getBest(res,pll(a,b));
		res = getBest(res,pll(a+1,b));
	}
	cout<<res.first<<'/'<<res.second<<endl;
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
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba
acaba
ba
bacb
*/