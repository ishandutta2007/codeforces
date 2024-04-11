#ifdef _MONYURA_
#pragma comment(linker,"/STACK:650000000")
#endif

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

struct film
{
	string name;
	int year;
	int gr;
};

vector<string> F[200][5];


void run()
{
	int n,m;
	cin>>n>>m;
	char A[20][20];
	rep(i,0,n)
		scanf("%s",A[i]);
	int res = 0;
	rep(i,0,n)
		rep(j,0,m)
			if (A[i][j]=='.')
			{
				bool row = 0;
				rep(c,0,m)
					if (A[i][c]=='S')
						row = 1;
				bool col = 0;
				rep(r,0,n)
					if (A[r][j]=='S')
						col = 1;
				res+=!col || !row;
			}
	cout<<res<<endl;
}



#define problem "dvd"

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