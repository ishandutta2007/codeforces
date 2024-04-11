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


int main()
{
	int n;
	ll x,y;
	cin>>n>>x>>y;
	ll *A=new ll[n];
	A[0]=y-n+1;
	rep(i,1,n)
		A[i]=1;
	if (A[0]<=0)
	{
		printf("-1\n");
		return 0;
	}
	if (A[0]<1e8)
	{
		if (A[0]*A[0]+n-1<x)
		{
			printf("-1\n");
			return 0;
		}
		rep(i,0,n)
			printf("%lld\n",A[i]);
		return 0;
	}
	rep(i,0,n)
		printf("%lld\n",A[i]);
	return 0;
}


/*




*/