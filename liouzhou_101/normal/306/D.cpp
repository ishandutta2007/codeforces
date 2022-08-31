#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

/*
#define X first
#define Y second
*/

typedef complex<ld> cd;
#define X real()
#define Y imag()

const int MaxN=110;
const cd I(0,1);
const ld pi=acos(-1);

int n;
cd p[MaxN];

int main()
{
	cin>>n;
	if (n<=4)
	{
		puts("No solution");
		return 0;
	}
	ld R=800,eps=0.5;
	if (n>10) R=1000;
	for (int i=0;i<n;++i)
		p[i]=R*exp(2*pi*i/n*I);
	ld len=0;
	for (int i=0;i<n-1;++i)
	{
		cd a=p[i]-p[i+1];
		cd b=p[(i+3)%n]-p[(i+2)%n];
		len+=eps;
		p[i+1]+=a/abs(a)*len;
		p[(i+2)%n]+=b/abs(b)*len;
	}
	for (int i=0;i<n;++i)
		printf("%.10lf %.10lf\n",p[i].X,p[i].Y);
	return 0;
}