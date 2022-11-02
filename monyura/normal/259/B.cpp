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
#include <cmath>
#include <queue>
#include <ctime>


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
typedef pair<ll,int> pli;

const double PI=acos(-1.0);



void run()
{
	int A[3][3];
	rep(i,0,3)
		rep(j,0,3)
			scanf("%d",&A[i][j]);
	int n=3;
	rep(v,1,100001)
	{
		int s = A[0][2]+v+A[2][0];
		A[1][1]=v;
		A[0][0]=s - A[0][1]-A[0][2];
		A[2][2]=s - A[2][0]-A[2][1];
		if (A[0][0]<=0 || A[2][2]<=0) continue;
		bool ok=1;
		rep(i,0,n)
		{
			int c=0;
			rep(j,0,n)
				c+=A[i][j];
			if (c!=s) ok=0;
		}
		rep(j,0,n)
		{
			int c=0;
			rep(i,0,n)
				c+=A[i][j];
			if (c!=s) ok=0;
		}
		if (A[0][0]+A[1][1]+A[2][2]!=s)
			ok=0;
		if (ok)
		{
			rep(i,0,n)
			{
				rep(j,0,n)
					printf("%d ",A[i][j]);
				puts("");
			}
			return;
		}
	}
}



int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("barns.in","r",stdin);
	//freopen("barns.out","w",stdout);
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