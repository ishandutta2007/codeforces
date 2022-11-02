#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
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
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

char A[101][10010];
int L[101][10001];
int R[101][10001];
void run()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,n)
		scanf("%s",A[i]);
	const int INF=1e9;
	rep(i,0,n)
	{
		int lft=-1;
		rep(j,0,m)
			if (A[i][j]=='1')
				lft=j;
		if (lft==-1)
		{
			puts("-1");
			return;
		}
		rep(j,0,m)
		{
			if (A[i][j]=='1')
				lft=j;
			L[i][j]=lft;
		}
		int rght=-1;
		for (int j=m-1;j>=0;j--)
			if (A[i][j]=='1') rght=j;
		for (int j=m-1;j>=0;j--)
		{
			if (A[i][j]=='1')
				rght=j;
			R[i][j]=rght;
		}
	}
	int res=INF;
	rep(j,0,m)
	{
		int curr=0;
		rep(i,0,n)
			curr+=min((j-L[i][j]+m)%m,(R[i][j]-j+m)%m);
		res=min(curr,res);
	}
	printf("%d\n",res);

	
}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/