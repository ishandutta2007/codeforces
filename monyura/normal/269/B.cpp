#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
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
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI=acos(-1.0);


void run()
{
	int n,m;
	cin>>n>>m;
	int D[5001][5001]={0};
	const int INF=1e9;
	rep(i,0,n+1)
		rep(j,0,m+1)
			D[i][j]=INF;
	D[0][0] = 0;
	int A[5001];
	rep(i,0,n)
	{
		double x;
		scanf("%d%lf",A+i,&x);
	}
	rep(i,1,n+1)
	{
		D[i][0]=D[i-1][0]+1;
		int MN[5001]={D[i-1][0]};
		rep(j,1,m+1)
			MN[j]=min(MN[j-1],D[i-1][j]);
		rep(j,1,m+1)
			if (j==A[i-1])
			{
				D[i][j]=min(D[i-1][j],MN[j-1]);
			}
			else
				D[i][j]=D[i-1][j]+1;
	}
	int res=n;
	rep(j,0,m+1)
		res=min(res,D[n][j]);
	cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 92
11 10 92
*/