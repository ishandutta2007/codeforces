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
	int A[200]={0};
	int n;
	cin>>n;
	rep(i,1,n+1)
		if (n==1 || 2*i>n && (i^1)>n)
		{
			puts("-1");
			return;
		}
	rep(i,1,n+1)
		scanf("%d",A+i);
	int res=0;
	for (int i=n;i>=1;i--)
	{
		res+=A[i];
		int ind=i^1;
		A[ind]=max(0,A[ind]-A[i]);
		A[i/2]=max(0,A[i/2]-A[i]);
		A[i]=0;
	}
	cout<<res<<endl;
}


int main()
{
	srand(time(0));
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

*/