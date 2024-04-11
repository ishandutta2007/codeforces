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
	int n,k;
	cin>>n>>k;
	int A[1001];
	int B[1001];
	rep(i,0,k)
		scanf("%d",A+i);
	memcpy(B,A,sizeof(A));
	int mn=0;
	rep(t,0,n)
	{
		int ind=-1;
		rep(i,0,k)
			if (A[i] && (ind==-1 || A[i]<A[ind]))
				ind=i;
		mn+=A[ind];
		--A[ind];
	}
	int mx=0;
	rep(t,0,n)
	{
		int ind=-1;
		rep(i,0,k)
			if (B[i] && (ind==-1 || B[i]>B[ind]))
				ind=i;
		mx+=B[ind];
		--B[ind];
	}
	printf("%d %d\n",mx,mn);

}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("final.in","r",stdin);
	//freopen("final.out","w",stdout);
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