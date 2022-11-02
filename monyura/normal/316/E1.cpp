#pragma comment(linker,"/STACK:65000000")
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

const double PI = acos(-1.0);

const int mod=1e9;

void run()
{
	int n,m;
	cin>>n>>m;
	int A[200];
	rep(i,0,n)
		scanf("%d",A+i);
	ll F[200]={1,1};
	rep(i,2,200)
		F[i]=(F[i-1]+F[i-2])%mod;
	rep(i,0,m)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int x,v;
			scanf("%d%d",&x,&v);
			--x;
			A[x]=v;
		}
		else if (t==2)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			--l;--r;
			int res = 0;
			rep(j,0,r-l+1)
				res=(res+A[l+j]*F[j]) % mod;
			printf("%d\n",res);
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
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/