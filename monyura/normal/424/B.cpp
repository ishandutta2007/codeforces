#pragma comment(linker,"/STACK:256000000")

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


const int SZ = 1000100;
int X[SZ],Y[SZ],K[SZ];
void run()
{
	int n,s;
	cin>>n>>s;
	rep(i,0,n)
	{
		scanf("%d%d%d",X+i,Y+i,K+i);
		X[i] *= X[i];
		Y[i] *= Y[i];
	}
	double res = -1;
	double l = 0, r = 4e4;
	const double eps = 1e-8;
	rep(i,0,60)
	{
		double c = (l+r)/2;
		double sq = c*c;
		int sum = s;
		rep(i,0,n)
			if (X[i]+Y[i] < sq + eps)
				sum += K[i];
		if (sum >= 1000000)
		{
			res = c;
			r = c;
		}
		else
			l = c;
	}
	if (res < 0)
		puts("-1");
	else
		printf("%.10lf\n",res);

	
}


//#define prob "island2"


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