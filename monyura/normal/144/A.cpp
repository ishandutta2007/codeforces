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
	int n;
	cin>>n;
	int A[1000];
	rep(i,0,n)
		scanf("%d",A+i);
	int mx=0;
	rep(i,1,n)
		if (A[i]>A[mx])
			mx=i;
	int mn=0;
	rep(i,1,n)
		if (A[i]<=A[mn])
			mn=i;
	if (A[mn]==A[mx])
		printf("0\n");
	else
	{
		int res=mx+n-1-mn;
		if (mx>mn)
			res-=1;
		printf("%d\n",res);
	}
	return 0;
} 

/*

*/