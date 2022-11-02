//#pragma comment(linker,"/STACK:62000000")
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

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int f(int n,int m)
{
	int a=m/2+m%2;
	int b=m-a;
	int c1=n/2+n%2;
	return max(a*c1+(n-c1)*b,b*c1+(n-c1)*a);
}

int f2(int n,int m)
{
	if (n==1) return m;
	if (m==2)
	{
		int res=(n/4)*4;
		if (n%4==1 || n%4==2) res+=(n%4)*2;
		if (n%4==3) res+=4;
		return res;
	}
	return 0;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int r=max(f(n,m),f(m,n));
	r=max(r,max(f2(n,m),f2(m,n)));
	printf("%d\n",r);
	return 0;
} 

/*

*/