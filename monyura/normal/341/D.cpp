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

ll FenXY[1002][1002];
ll FenX[1002][1002];
ll FenY[1002][1002];
ll Fen[1002][1002];
int Fsize;

void addPoint(int x,int y, ll val)
{
	for (int i = x; i<=Fsize; i += i&-i)
		for (int j = y; j<=Fsize; j += j&-j)
		{
			if (x & y & 1) FenXY[i][j] ^= val;
			if (x & 1) FenX[i][j] ^= val;
			if (y & 1) FenY[i][j] ^= val;
			Fen[i][j] ^= val;
		}
}

void addRect(int x0, int x1, int y0, int y1, ll val)
{
	addPoint(x0,y0,val);
	addPoint(x1+1,y0,val);
	addPoint(x0,y1+1,val);
	addPoint(x1+1,y1+1,val);
}

ll getPoint(int x, int y)
{
	ll res = 0;
	for (int i = x; i>0; i -= i&-i)
		for (int j = y; j>0; j -= j&-j)
		{
			res ^= FenXY[i][j];
			if ((y+1) & 1) res ^= FenX[i][j];
			if ((x+1) & 1) res ^= FenY[i][j];
			if ((x+1) & (y+1) & 1) res ^= Fen[i][j];
		}
	return res;
}

ll getRect(int x0, int x1, int y0, int y1)
{
	ll res = 0;
	res ^= getPoint(x1, y1);
	res ^= getPoint(x0 - 1, y0 - 1);
	res ^= getPoint(x1, y0 - 1);
	res ^= getPoint(x0 - 1, y1);
	return res;
}

void run()
{
	int n;
	cin>>n;
	Fsize = n+1;
	int q;
	cin>>q;
	rep(i,0,q)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int x0, y0, x1, y1;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			ll res = getRect(x0, x1, y0, y1);
			printf("%I64d\n",res);
		}
		else
		{
			int x0, y0, x1, y1;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			ll b;
			scanf("%I64d",&b);
			addRect(x0, x1, y0, y1, b);
		}
	}
}

//#define prob "tria"

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