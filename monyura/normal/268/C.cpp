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

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI=acos(-1.0);

const int mod = 1e9+7;
const int mod2 = 999999937;
const ll q = 19171;
const ll p = 253;
ll Qn[10001];
ll Pn[10001];

void run()
{
	int n,m;
	cin>>n>>m;
	pii A[200];
	vector<pii> res;
	rep(i,0,min(n,m)+1)
		res.push_back(pii(i,m-i));
	/*if (n==m)
	{
		rep(i,0,n+1)
		{
			A[i]=pii(i,i);
			if (i%3==0)
				A[i].second++;
			if (i%3==1)
				A[i].second--;
			if (A[i].first<=n && A[i].second<=m)
				res.push_back(A[i]);
		}
		if (n%3==0)
			res.push_back(pii(n,n));
	}
	else
		rep(i,0,min(n,m)+1)
			res.push_back(pii(n-i,m-i));*/
	printf("%d\n",res.size());
	rep(i,0,res.size())
		printf("%d %d\n",res[i].first,res[i].second);
	
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
10 10 92
11 10 92
*/