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

const double PI = acos(-1.0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;


void run()
{
	int n;
	cin>>n;
	int A[1001];
	rep(i,0,n)
		scanf("%d",A+i);
	int S[2] = {0};
	int l = 0 , r = n-1;
	rep(i,0,n)
	{
		if (A[l] > A[r])
			S[i&1] += A[l++];
		else
			S[i&1] += A[r--];
	}
	printf("%d %d\n",S[0],S[1]);
}	


//#define prob "xoring"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
	run();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}