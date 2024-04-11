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


void run()
{
	int n;
	cin>>n;
	int A[2001];
	rep(i,0,n)
		scanf("%d",A+i);
	map<int,int> mp;
	vector<pii> V[2001];
	int res = 0;
	rep(i,0,n)
	{
		int absA = abs(A[i]);
		int left  = 0;
		rep(j,0,i)
			left += abs(A[j]) < absA;
		int right = 0;
		rep(j,i+1,n)
			right += abs(A[j]) < absA;
		if (mp.find(absA) == mp.end())
		{
			int size = mp.size();
			mp[absA] = size;
		}
		int id = mp[absA];
		V[id].push_back(pii(left,right));
	}
	const int INF = 1e9;
	int D[2005][2005];
	rep(a,0,mp.size())
	{
		vector<pii> &vec = V[a];
		int m = vec.size();
		rep(i,0,m+2)
			rep(j,0,m+2)
				D[i][j] = INF;
		D[0][0] = 0;
		rep(i,1,m+1)
		{
			int l = vec[i-1].first;
			int r = vec[i-1].second;
			rep(j,0,m+1)
			{
				D[i][j] = D[i-1][j] + l + j;
				if (j>0)
					D[i][j] = min(D[i][j], D[i-1][j-1] + r);
			}
		}
		int curr = INF;
		rep(i,0,m+1)
			curr = min(curr, D[m][i]);
		res += curr;
	}
	cout<<res<<endl;
	
}

//#define prob "kids"

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