#pragma comment(linker,"/STACK:32000000")
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

struct point
{
	ll x,y;
	point(ll x0=0,ll y0=0)
	{
		x=x0;
		y=y0;
	}
};

point operator-(const point &a,const point &b)
{
	return point(a.x-b.x,a.y-b.y);
}

bool perp(point &a,point &b)
{
	return a.x*b.x+a.y*b.y==0;
}

int main()
{
	point A[8];
	rep(i,0,8)
		cin>>A[i].x>>A[i].y;
	int p[8];
	rep(i,0,8)
		p[i]=i;
	do
	{
		bool ok=1;
		rep(i,0,3)
			if (SQR(A[p[i]].x-A[p[i+1]].x)+SQR(A[p[i]].y-A[p[i+1]].y)!=SQR(A[p[0]].x-A[p[1]].x)+SQR(A[p[0]].y-A[p[1]].y))
				ok=0;
		if (SQR(A[p[0]].x-A[p[3]].x)+SQR(A[p[0]].y-A[p[3]].y)!=SQR(A[p[0]].x-A[p[1]].x)+SQR(A[p[0]].y-A[p[1]].y))
			ok=0;
		rep(i,0,4)
			if (!perp(A[p[(i+1)%4]]-A[p[i]],A[p[(i+2)%4]]-A[p[(i+1)%4]]))
				ok=0;
		int *r=p+4;
		rep(i,0,4)
			if (!perp(A[r[(i+1)%4]]-A[r[i]],A[r[(i+2)%4]]-A[r[(i+1)%4]]))
				ok=0;
		if (SQR(A[r[0]].x-A[r[1]].x)+SQR(A[r[0]].y-A[r[1]].y)!=SQR(A[r[2]].x-A[r[3]].x)+SQR(A[r[2]].y-A[r[3]].y))
			ok=0;
		if (SQR(A[r[0]].x-A[r[3]].x)+SQR(A[r[0]].y-A[r[3]].y)!=SQR(A[r[2]].x-A[r[1]].x)+SQR(A[r[2]].y-A[r[1]].y))
			ok=0;
		if (ok)
		{
			printf("YES\n");
			rep(i,0,4)
				printf("%d ",p[i]+1);
			printf("\n");
			rep(i,0,4)
				printf("%d ",r[i]+1);
			printf("\n");
			return 0;
		}
	}
	while (next_permutation(p,p+8));
	printf("NO\n");

	return 0;
} 
/*
a b c d e f g b
b a c a c b c
*/