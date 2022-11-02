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
	vector<int> V[100100];
	int A[100100];
	map<int, int> mp;
	rep(i,0,n)
	{
		scanf("%d",A+i);
		if (mp.find(A[i])==mp.end())
		{
			int size = mp.size();
			mp[A[i]] = size;
		}
		V[mp[A[i]]].push_back(i);
	}
	vector<pii> res;
	for (map<int, int >::iterator iter = mp.begin(); iter!=mp.end(); ++iter)
	{
		vector<int> &vec = V[iter->second];
		int diff = vec.size() > 1 ? vec[1] - vec[0] : 0;
		rep(i,1,vec.size())
			if (vec[i] - vec[i-1] != diff)
				diff = -1;
		if (diff!=-1)
			res.push_back(pii(iter->first, diff));
	}
	printf("%d\n",res.size());
	rep(i,0,res.size())
		printf("%d %d\n",res[i].first,res[i].second);


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