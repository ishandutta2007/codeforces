#pragma comment(linker,"/STACK:128000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}



void run()
{
	int n,a,d;
	int Ans[100100];
	cin>>n>>a>>d;
	int T[100100],V[100100];
	double mx=0;
	rep(i,0,n)
	{
		double t,v;
		scanf("%lf%lf",&t,&v);
		double t1=v/a;
		double d1=a*t1*t1/2;
		if (d1>d)
		{
			d1=d;
			t1=sqrt(2.0*d/a);
		}
		double t2=(d-d1)/v;
		double r=t1+t2+t;
		if (r<mx)
			r=mx;
		else
			mx=r;
		printf("%.8lf\n",r);
	}
	
}

int main()
{
#ifdef _MON_JUDGE_
	freopen("test.txt","r",stdin);
	freopen("res.txt","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/