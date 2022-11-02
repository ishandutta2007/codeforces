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
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI=acos(-1.0);

void buildRec(int n,int r,vector<pii> &v,double st)
{
	double Ang = 0;
	double add = 2*PI/n;
	rep(i,0,n)
	{
		Ang=add*i + st;
		v.push_back(pii(r*cos(Ang),r*sin(Ang)));
	}
}

void run()
{
	int n;
	int D[101];
	cin>>n;
	rep(i,0,n)
		scanf("%d",D+i);
	int s = accumulate(D,D+n,0);
	int a,b;
	scanf("%d%d",&a,&b);
	--a;--b;
	if (a>b) swap(a,b);
	int has = 0;
	rep(i,a,b)
		has+=D[i];
	cout<<min(has,s-has)<<endl;


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