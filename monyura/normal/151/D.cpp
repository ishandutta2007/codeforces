#pragma comment(linker,"/STACK:128000000")
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
#define x first
#define y second

const double PI=acos(-1.0);

int M=1000000007 ;

int toPow(ll a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)
			res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if (k&1)
	{
		if (k==n)
			printf("%d\n",(ll(m)*toPow(m,n/2))%M);
		else if (k>n || k==1)
			printf("%d\n",toPow(m,n));
		else
			printf("%d\n",m*m);
	}
	else
	{
		if (k==n)
			printf("%d\n",toPow(m,n/2));
		else if (k>n)
			printf("%d\n",toPow(m,n));
		else
			printf("%d\n",m);
	}
	return 0;
} 

/*
10000000000000

*/