#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;
const ld pi=(ld)3.1415926535897932384626;

ld n,m,a;

void answer(ld x)
{
	printf("%.20lf\n",(double)x);
}

int main()
{
	cin>>n>>m>>a;
	if (n<m)
	{
		swap(n,m);
		a=180-a;
	}
	if (a>90) a=180-a;
	if (a==0)
		answer(n*m);
	else if (a==90)
		answer(min(n,m)*min(n,m));
	else
	{
		a=a*pi/180;
		ld c=atan(m/n);
		if (a>=c*2)
		{
			answer(m*m/sin(a));
		}
		else
		{
			ld x=(m-(1/sin(a)+1/tan(a))*n)/(sin(a)-(1+cos(a))*(1/sin(a)+1/tan(a)));
			ld y=n-x*(1+cos(a));
			answer(n*m-(x*x*sin(a)*cos(a)+y*y/tan(a)));
		}
	}
	return 0;
}