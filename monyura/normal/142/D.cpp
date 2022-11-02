#pragma comment(linker,"/STACK:62000000")
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
	int n,m,k;
	cin>>n>>m>>k;
	char A[101][102];
	rep(i,0,n)
		scanf(" %s",A+i);
	bool R=0,G=0;
	int cnt=n*m;
	int tG=0;
	rep(i,0,n)
	{
		int r=0,g=0;
		rep(j,0,m)
			if (A[i][j]=='R') r++;
			else if (A[i][j]=='G') g++;
			else --cnt;
		if (g<m)
			tG+=g;
		if (g && !r && g<m) G=1;
		if (r && !g && r<m) R=1;
	}
	if (R && G)
	{
		printf("Draw\n");
		return 0;
	}
	if (G)
	{
		printf("First\n");
		return 0;
	}
	if (R || tG==0)
	{
		printf("Second\n");
		return 0;
	}
	int B[100];
	int pos=0;
	rep(i,0,n)
	{
		int g=0,r=0;
		rep(j,0,m)
			if (A[i][j]=='G') g=j;
			else if (A[i][j]=='R') r=j;
		if (g!=r)
			B[pos++]=abs(g-r)-1;
	}
	int K[10]={0};
	rep(i,0,n)
		rep(j,0,10)
			K[j]=(K[j]+((B[i]>>j)&1))%(k+1);
	if (*max_element(K,K+10)==0)
		printf("Second\n");
	else
		printf("First\n");
	return 0;
} 

/*
2 1 1
-
G
*/