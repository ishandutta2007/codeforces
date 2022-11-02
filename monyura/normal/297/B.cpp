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
	int n,m,k;
	cin>>n>>m>>k;
	multiset<int> A;
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		A.insert(a);
	}
	vector<pii> vec;
	rep(i,0,m)
	{
		int b;
		scanf("%d",&b);
		multiset<int>::iterator iter = A.find(b);
		if (iter!=A.end())
			A.erase(iter);
		else
			vec.push_back(pii(b,-1));
	}
	for (multiset<int>::iterator iter = A.begin();iter!=A.end();++iter)
		vec.push_back(pii(*iter,1));
	sort(all(vec),greater<pii>());
	int bal = 0;
	rep(i,0,vec.size())
	{
		bal+=vec[i].second;
		if (bal>0)
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("path.in","r",stdin);
	//freopen("path.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*

*/