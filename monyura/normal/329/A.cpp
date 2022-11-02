#pragma comment(linker,"/STACK:650000000")
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

void run()
{
	char A[102][102];
	int n;
	cin>>n;
	rep(i,0,n)
		scanf("%s",A[i]);
	vector<pii> res;
	rep(i,0,n)
	{
		bool ok = false;
		rep(j,0,n)
			ok |= A[i][j]=='.';
		if (!ok)
		{
			rep(j,0,n)
			{
				bool curr = false;
				rep(i,0,n)
					curr |= A[i][j]=='.';
				if (!curr)
				{
					puts("-1");
					return;
				}
			}
			rep(j,0,n)
				rep(i,0,n)
				{
					if (A[i][j]=='.')
					{
						res.push_back(pii(i,j));
						break;
					}
				}
			break;
		}
	}
	if (res.empty())
		rep(i,0,n)
			rep(j,0,n)
			if (A[i][j]=='.')
			{
				res.push_back(pii(i,j));
				break;
			}
	rep(i,0,res.size())
		printf("%d %d\n",res[i].first+1,res[i].second+1);
}

//#define problem "party"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(problem".in","r",stdin);
	//freopen(problem".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}