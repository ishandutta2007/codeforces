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
	bool A[10]={0};
	int x;
	scanf("%d",&x);
	int t=x;
	while (t)
	{
		A[t%10]=1;
		t/=10;
	}
	int i;
	int res=0;
	for (i=1;i*i<x;i++)
		if (x%i==0)
		{
			int B[2]={i,x/i};
			rep(j,0,2)
			{
				int t=B[j];
				bool ok=0;
				while (t)
				{
					if (A[t%10]) ok=1;
					t/=10;
				}
				res+=ok;
			}
		}
	if (i*i==x)
	{
		int t=i;
		bool ok=0;
		while (t)
		{
			if (A[t%10]) ok=1;
			t/=10;
		}
		res+=ok;
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