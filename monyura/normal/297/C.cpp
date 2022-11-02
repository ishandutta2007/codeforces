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
	pii S[100100];
	int n;
	cin>>n;
	rep(i,0,n)
	{
		pii p;
		scanf("%d",&p.first);
		p.second = i;
		S[i]=p;
	}
	sort(S,S+n);
	int A[100100]={0};
	int B[100100]={0};
	int tr = (n+2)/3;
	rep(i,0,tr)
		A[S[i].second]=i;
	rep(i,2*tr,n)
		A[S[i].second]=S[i].first- (--tr);
	rep(i,0,n)
		B[S[i].second]=S[i].first-A[S[i].second];
	puts("YES");
	rep(i,0,n)
		printf("%d ",A[i]);
	puts("");
	rep(i,0,n)
		printf("%d ",B[i]);
	puts("");
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