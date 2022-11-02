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

const int mod = 1e9+7;
const int mod2 = 999999937;
const ll q = 19171;
const ll p = 253;
ll Qn[10001];
ll Pn[10001];

bool cmp(const pii &a,const pii &b)
{
	//return a.second>b.second;
	return a.first*a.second * (100-b.second) > b.first*b.second*(100-a.second);
}

double getRes(pii *A,int n)
{
	double M,prevM=0,L,prevL=0;
	rep(i,0,n)
	{
		int l = A[i].first;
		double p =A[i].second/100.0;
		M = prevM + l + (1-p)*prevL;
		L = prevL + p * l;
		prevM = M;
		prevL = L;
	}
	return M;
}


void run()
{
	int n;
	cin>>n;
	pii A[50001];
	rep(i,0,n)
		scanf("%d %d\n",&A[i].first,&A[i].second);
	sort(A,A+n,cmp);
	int f=1;
	rep(i,1,n+1)
		f*=i;
	double rm=0;
	/*rep(i,0,f)
	{
		double res=getRes(A,n);
		rm=max(res,rm);
		printf("%.10lf\n",res);
		next_permutation(A,A+n);
	}*/
	double res=getRes(A,n);
	printf("%.10lf\n",res);
	//printf("Res = %.10lf\n",res);
	//printf("Max = %.10lf\n",rm);
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