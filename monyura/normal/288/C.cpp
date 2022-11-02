//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

#include <iostream>
#include <iomanip>
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

const double PI = acos(-1.0);

int Res[1000100]={0};
void solve(int n,int add)
{
	int st = 0;
	while ((1<<st)<n)
		++st;
	--st;
	if ((n&-n)==n)
	{
		rep(i,0,n)
			Res[i] = (~i)&(n-1)|add;
		return;
	}
	else
	{
		int p = 1<<st;
		rep(i,n-(1<<st),n)
			Res[i] = (~i)&(p-1)|add;
		solve(n-(1<<st),add|(1<<st));
	}
}

void run()
{
	/*int n;
	cin>>n;
	int A[12];
	rep(i,0,n)
		A[i] = i;
	int mx = 0;
	do
	{
		int res  = 0;
		rep(i,0,n)
			res+=i^A[i];
		mx=max(res,mx);
	}
	while (next_permutation(A,A+n));
	sort(A,A+n);
	do
	{
		int res  = 0;
		rep(i,0,n)
			res+=i^A[i];
		if (res==mx)
		{
			rep(i,0,n)
				printf("%d ",A[i]);
			puts("");
		}
	}
	while (next_permutation(A,A+n));
	cout<<mx<<endl;*/
	int n;
	cin>>n;
	n++;
	solve(n,0);
	ll res =0;
	rep(i,0,n)
		res+=Res[i]^i;
	cout<<res<<endl;
	rep(i,0,n)
		printf("%d ",Res[i]);
	puts("");
	
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
	printf( "=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}