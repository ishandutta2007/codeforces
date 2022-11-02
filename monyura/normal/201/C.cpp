#pragma comment(linker,"/STACK:64000000")
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
typedef pair<double,double> pdd;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

ll calc(int *A,int n)
{
	ll p0=0,p1=0,p2=0,c0,c1,c2;
	ll res=0;
	rep(i,0,n)
	{
		int even=A[i]&~1;
		int odd=(A[i]-1)|1;
		c0=c1=c2=0;
		if (even>=2)
			c0=max(p0,p2)+even;
		if (even>=4)
			movmax(c0,p1+even);
		if (even>=2)
			c1=p1+even;
		if (A[i]>=1)
			c2=max(p1,p2)+odd;
		p0=c0; p1=c1; p2=c2;
		movmax(res,c0);
		movmax(res,c1);
		movmax(res,c2);
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	int A[100100];
	rep(i,0,n-1)
		scanf("%d",A+i);
	ll res=calc(A,n-1);
	cout<<res<<endl;
	return 0;
}
/*
5
2 1 2 1
*/