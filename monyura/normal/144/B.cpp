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

int main()
{
	int xa,ya,xb,yb;
	cin>>xa>>ya>>xb>>yb;
	if (xa>xb) swap(xa,xb);
	if (ya>yb) swap(ya,yb);
	int n;
	cin>>n;
	bool B[4][3000]={0};
	int tot=0;
	rep(j,0,n)
	{
		int x,y,r;
		cin>>x>>y>>r;
		int i=0;
		rep(xc,xa,xb+1)
		{
			if (SQR(x-xc)+SQR(y-ya)<=r*r)
				B[0][i]=1;
			if (SQR(x-xc)+SQR(y-yb)<=r*r)
				B[1][i]=1;
			i++;
		}
		i=0;
		rep(yc,ya,yb+1)
		{
			if (SQR(y-yc)+SQR(x-xa)<=r*r)
				B[2][i]=1;
			if (SQR(y-yc)+SQR(x-xb)<=r*r)
				B[3][i]=1;
			i++;
		}
	}
	rep(i,0,xb-xa+1)
		tot+=2-B[0][i]-B[1][i];
	rep(i,1,yb-ya)
		tot+=2-B[2][i]-B[3][i];
	printf("%d\n",tot);

	return 0;
} 

/*

*/