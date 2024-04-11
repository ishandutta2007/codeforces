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
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


int main()
{
	int n,j,res=-1;
	cin>>n;
	char A[30100][22];
	rep(i,0,n) scanf(" %s",A[i]);
	for (j=0;j<21 && res==-1;j++)
		rep(i,1,n)
			if (A[i][j]!=A[0][j] || A[i][j]==0)
				res=j;
	printf("%d\n",res);
	return 0;
}

/*
{68, 12, 60}, 66, 8,
7
4 17
3 7
2 7
14 31
10007 20011
2 7
2 7
*/