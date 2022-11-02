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
	bool used[1001]={0};
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		used[a]=used[b]=1;
	}
	rep(i,1,n+1)
		if (!used[i])
		{
			printf("%d\n",n-1);
			rep(j,1,n+1)
				if (i!=j)
					printf("%d %d\n",i,j);
			return;
		}

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