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

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define x first
#define y second

const double PI=acos(-1.0);

int main()
{
	int n,k;
	cin>>n>>k;
	pii A[5000];
	rep(i,0,n)
		scanf("%d%d",&A[i].x,&A[i].y);
	A[n++]=pii(86401,1);
	int res=0;
	int D1[4010],D2[4010];
	int *P=D1,*D=D2;
	P[0]=1;
	rep(i,1,k+1)
		P[i]=100000;
	rep(i,0,n)
	{
		rep(j,0,k+1)
			if (A[i].x<=P[j]) D[j]=P[j]+A[i].y;
			else
			{
				res=max(res,A[i].x-P[j]);
				D[j]=A[i].x+A[i].y;
			}
		rep(j,1,k+1)
			D[j]=min(D[j],P[j-1]);
		swap(D,P);
	}
	printf("%d\n",res);
	return 0;
} 

/*
8 0
1 1
10000 1
20000 1
30000 1
40000 1
50000 1
60000 1
70000 1
16400

1 0
1 86400
20000 80000

3 2
1 2
2 80000
10 75000

4 2
2 5
3 1
4 1
9 2 


*/