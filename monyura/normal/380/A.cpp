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


int T[100100],A[100100],B[100100];
void run()
{
	
	int m;
	cin>>m;
	rep(i,0,m)
	{
		scanf("%d",T+i);
		if (T[i] == 1)
			scanf("%d",A+i);
		else
			scanf("%d%d",A+i,B+i);
	}
	int n;
	cin>>n;
	int pos = 0;
	ll len = 0;
	int Pos[100100];
	int Ans[100100];
	memset(Ans,-1,sizeof(Ans));
	rep(i,0,n)
	{
		ll a;
		scanf("%I64d", &a);
		--a;
		while (pos < m)
		{
			ll nxtLen = len + (T[pos] == 1 ? 1 : A[pos] * B[pos]);
			if (nxtLen > a)
				break;
			len = nxtLen;
			pos++;
		}
		if (T[pos] == 1)
		{
			Ans[i] = A[pos];
		}
		else
			Pos[i] = (a - len) % A[pos];
	}
	int Arr[200200];
	len = 0;
	rep(i,0,m)
	{
		if (T[i] == 1)
			Arr[len++] = A[i];
		else
		{
			int l = A[i];
			int c = B[i];
			rep(j,0,c)
			{
				rep(k,0,l)
					Arr[len++] = Arr[k];
				if (len > 100100)
					break;
			}
		}
		if (len > 100100)
			break;
	}
	rep(i,0,n)
		if (Ans[i] == -1)
			Ans[i] = Arr[Pos[i]];
	rep(i,0,n)
		printf("%d ",Ans[i]);
	puts("");
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