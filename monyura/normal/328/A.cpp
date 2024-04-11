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
	int A[4];
	rep(i,0,4)
		scanf("%d",A+i);
	rep(d,-1001,1001)
	{
		int B[4]={A[0],A[0]+d,A[0]+2*d,A[0]+3*d};
		if (memcmp(A,B,sizeof(A))==0)
		{
			printf("%d\n",A[0]+4*d);
			return;
		}
	}
	if (A[0]!=0)
	{
		int num = A[1], denom = A[0];
		ll B[4]={A[0]};
		bool fail = false;
		rep(i,1,4)
		{
			B[i]=B[i-1]*num;
			if (B[i]%denom!=0)
				fail = true;
			B[i]/=denom;
		}
		rep(i,0,4)
			if (A[i]!=B[i])
				fail = true;
		ll nxt = A[3]*num;
		if (nxt%denom!=0)
			fail = true;
		nxt/=denom;
		if (!fail)
		{
			cout<<nxt<<endl;
			return;
		}
	}
	puts("42");
}

#define problem "party"


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