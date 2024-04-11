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

int P[501];
int X[501];
vector<double> rad;
vector<int> s;

void relax(int i,int j)
{
	int t=s[j];
	rad[i]=min(rad[i],(X[i]-X[t])*(X[i]-X[t])/(4.0*rad[t]));
}

void relax2(int i,int j)
{
	int t=s[j];
	rad[i]=min(rad[i],(X[i]-X[t])*(X[i]-X[t])/(4.0*rad[t]*rad[t]));
}


double calc(int n)
{
	rad.clear();
	s.clear();
	double sum=0;
	rep(i,0,n)
	{
		rad.push_back(P[i]);
		rep(j,0,min((int)s.size(),301))
			relax(i,s.size()-j-1);
		while (!s.empty() && rad[s.back()]<=rad[i])
			s.pop_back();
		s.push_back(i);
		sum+=rad[i];
	}
	return sum;
}

double real(int n)
{
	rad.clear();
	s.clear();
	double sum=0;
	rep(i,0,n)
	{
		rad.push_back(P[i]);
		rep(j,0,s.size())
			relax(i,s.size()-j-1);
		while (!s.empty() && rad[s.back()]<=rad[i])
			s.pop_back();
		s.push_back(i);
		sum+=rad[i];
	}
	return sum;
}

void test()
{
	int n=302;
	P[0]=200000;
	X[0]=0;
	P[1]=301;
	X[1]=20000;
	rep(i,2,n)
	{
		P[i]=302-i;
		X[i]=X[i-1]+P[i-1]+P[i];
	}
	X[n]=500000;
	P[n]=1000000;
	n++;
	printf("%d\n",n);
	rep(i,0,n)
		printf("%d %d\n",X[i],P[i]);
}

void run()
{
	test();
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
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