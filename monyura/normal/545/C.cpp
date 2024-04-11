#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
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
#include <bitset>
#include <sstream>
#include <cassert>
#include <utility>
#include <iterator>

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
typedef pair<double, int> pdi;


int D[100100][2] = {0};
void run()
{
	int n;
	cin>>n;
	int X[100100];
	int H[100100];
	rep(i,0,n)
		scanf("%d%d", X+i, H+i);
	D[0][0] = 1;
	D[0][1] = 0;
	rep(i,1,n)
	{
		D[i][0] = D[i-1][0];
		if (X[i] - X[i-1] > H[i])
			D[i][0] = max(D[i][0], D[i-1][0] + 1);
		if (X[i] - X[i-1] > H[i-1] + H[i])
			D[i][0] = max(D[i][0], D[i-1][1] + 1);
		if (X[i] - X[i-1] > H[i-1])
			D[i][0] = max(D[i][0], D[i-1][1]);
		if (i == n-1 || X[i+1] - X[i] > H[i])
			D[i][1] = max(D[i][1], D[i-1][0] + 1);
		if (i == n-1 || X[i+1] - X[i] > H[i])
			D[i][1] = max(D[i][1], D[i-1][1] + 1);
//		cout<<i<<')'<<D[i][0]<<' '<<D[i][1]<<endl;
	}
	cout<<max(D[n-1][0], D[n-1][1])<<endl;


}

//#define prob "i"

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
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