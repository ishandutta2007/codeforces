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


int toL[301][301][301]={0};
int toR[301][301][301]={0};
int tp,tu,td;
inline int getVal(int fr,int to)
{
	if (fr == to)
		return tp;
	return fr > to ? td : tu;
}

void run()
{
	int n,m,t;
	cin>>n>>m>>t;
	cin>>tp>>tu>>td;
	int A[301][301];
	rep(i,0,n)
		rep(j,0,m)
			scanf("%d",&A[i][j]);
	rep(i,0,n)
	{
		rep(j0,0,m)
		{
			toR[i][j0][j0] = 0;
			rep(j1,j0+1,m)
				toR[i][j0][j1] = toR[i][j0][j1-1] + getVal(A[i][j1-1],A[i][j1]);
		}
		rep(j1,0,m)
		{
			toL[i][j1][j1] = 0;
			for (int j0 = j1-1;j0>=0; j0--)
				toL[i][j0][j1] = toL[i][j0+1][j1] + getVal(A[i][j0+1],A[i][j0]);
		}
	}
	set<pii>::iterator iter;
	int diff = 1e9;
	int a,b,c,d;
	rep(j0,0,m)
		rep(j1,j0+2,m)
		{
			set<pii> st;
			int sumPrev = 0;
			int sum = getVal(A[1][j0],A[0][j0]) + getVal(A[0][j1], A[1][j1]);
			rep(i,2,n)
			{
				sum += getVal(A[i][j0],A[i-1][j0]) + getVal(A[i-1][j1],A[i][j1]);
				int pr = i-2;
				st.insert(pii(-sumPrev + toR[pr][j0][j1], pr));
				int has = sum + toL[i][j0][j1];
				int need = t - has;
				iter = st.lower_bound(pii(need,-1));
				if (iter != st.end())
				{
					int curr = abs(t - has - iter->first);
					if (curr < diff)
					{
						diff = curr;
						a = iter->second; b = j0; c = i; d = j1;
					}
				}
				if (iter != st.begin())
				{
					--iter;
					int curr = abs(t - has - iter->first);
					if (curr < diff)
					{
						diff = curr;
						a = iter->second; b = j0; c = i; d = j1;
					}
				}
				sumPrev += getVal(A[pr+1][j0], A[pr][j0]) + getVal(A[pr][j1],A[pr+1][j1]);
			}
		}
	printf("%d %d %d %d\n",a+1,b+1,c+1,d+1);		
	//cout<<diff<<endl;
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