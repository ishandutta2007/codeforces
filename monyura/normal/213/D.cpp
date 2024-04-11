#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

typedef pair<double,double> pdd;

struct star
{
	double X[5],Y[5];
	int Id[5];
	void init(double a,double b,double Al,int id0)
	{
		double x=10,y=0;
		X[0]=a;
		Y[0]=b;
		rep(i,1,5)
		{
			X[i]=X[i-1]+x;
			Y[i]=Y[i-1]+y;
			double nx=cos(Al)*x-sin(Al)*y;
			double ny=sin(Al)*x+cos(Al)*y;
			x=nx;
			y=ny;
		}
		rep(i,0,5)
			Id[i]=i+id0+1;
	}
};


void run()
{
	int n;
	cin>>n;
	star S[100];
	double Ang=2*PI/5;
	S[0].init(0,0,Ang,0);
	int cnt=6;
	rep(i,1,n)
	{
		double Al=Ang;;
		if (i&1)
			Al=-Ang;
		S[i].init(S[i-1].X[2],S[i-1].Y[2],Al,0);
		rep(j,1,4)
			S[i].Id[j]=cnt++;
		S[i].Id[0]=S[i-1].Id[2];
		S[i].Id[4]=S[i-1].Id[1];
	}
	printf("%d\n",5+3*(n-1));
	rep(i,0,5)
		printf("%.10lf %.10lf\n",S[0].X[i],S[0].Y[i]);
	rep(j,1,n)
		rep(i,1,4)
			printf("%.10lf %.10lf\n",S[j].X[i],S[j].Y[i]);
	rep(i,0,n)
	{
		rep(j,0,5)
			printf("%d%c",S[i].Id[j],(j==4?'\n':' '));
	}
	int P1[5]={1,3,0,2};
	int P0[3]={3,1};
	printf("%d",S[0].Id[0]);
	rep(i,0,n)
		if (i&1)
		{
			rep(j,0,4)
				printf(" %d",S[i].Id[P1[j]]);
		}
		else
		{
			rep(j,0,2)
				printf(" %d",S[i].Id[P0[j]]);
		}
	int S0[5]={1,4,2,0};
	if (n&1)
		rep(j,1,4)
			printf(" %d",S[n-1].Id[S0[j]]);
	for (int i=n-2;i>=0;i--)
		if ((i&1)==0)
		{
			rep(j,0,4)
				printf(" %d",S[i].Id[S0[j]]);
		}
	putchar('\n');
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/