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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

ll nod(ll a,ll b)
{
	ll c=0;
	while (b>0)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return c;
}

ll nok(ll a,ll b)
{
	return a*b/nod(a,b);
}

int main()
{
	ll a,b;
	cin>>a>>b;
	ll toa=0,tob=0;
	if (a>b)
	{
		ll nk=nok(a,b);
		for (int i=1;i<=nk/a;i++)
			toa+=(i*a)%b;
		toa+=b;
		tob=nk-toa;
	}
	else
	{
		ll nk=nok(a,b);
		for (int i=1;i<=nk/b;i++)
			tob+=(i*b)%a;
		tob+=a;
		toa=nk-tob;
	}
	if (toa==tob) puts("Equal");
	else if (toa>tob) puts("Dasha");
	else puts("Masha");
	return 0;	
}
/*
*/