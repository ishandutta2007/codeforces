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

const int SZ = 1000100;
int upTo[SZ];
void init()
{
	upTo[0] = 0;
	upTo[1] = 2;
	rep(i,2,SZ)
		upTo[i] = upTo[i-1] + 1 + ((i&-i)==i);
}



void run()
{
	init();
	int n,m;
	cin>>n>>m;
	vector<int> L[7001],R[7001],X[7001];
	int cnt = 0;
	map<int,int> mp;
	rep(i,0,m)
	{
		int q,t,l,r,x;
		scanf("%d",&q);
		if (q == 1)
		{
			scanf("%d%d%d%d",&t,&l,&r,&x);
			if (mp.find(x) == mp.end())
			{
				int sz = mp.size();
				mp[x] = sz;
			}
			x = mp[x];
			L[t].push_back(l);
			R[t].push_back(r);
			X[t].push_back(x);
			++cnt;
		}
		else
		{
			int t,v;
			scanf("%d%d",&t,&v);
			bool was[7001] = {0};
			int res = 0;
			int l = v, r = v;
			rep(lvl,t,n+1)
			{
				rep(j,0,L[lvl].size())
				{
					if (max(L[lvl][j], l) <= min(R[lvl][j], r))
					{
						if (!was[X[lvl][j]])
							++res;
						was[X[lvl][j]] = 1;
					}
				}
				l = upTo[l-1] + 1;
				r = upTo[r];
			}
			printf("%d\n",res);
		}
	}
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