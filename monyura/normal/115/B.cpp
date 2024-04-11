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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{
	int n,m;
	cin>>n>>m;
	char A[200][200];
	rep(i,0,n)
		scanf(" %s",A[i]);
	int L[150];
	int R[150];
	rep(i,0,n)
	{
		R[i]=L[i]=-1;
		rep(j,0,m)
			if (A[i][j]=='W') R[i]=j;
		for (int j=m-1;j>=0;j--)
			if (A[i][j]=='W') L[i]=j;
	}
	int pos=0,y=0;
	int res=0;
	int to=0;
	for (int i=0 ; ;i++)
	{
		while (i<n && L[i]==-1) i++;
		if (i==n) break;
		if (i!=y)
		{
			res+=i-y;
			if (i&1)
				res+=abs(R[i]-pos);
			else
				res+=abs(L[i]-pos);
			y=i;	
		}
		res+=R[y]-L[y];
		if (y&1)
			pos=L[y];
		else
			pos=R[y];
	}
	if (L[0]!=-1)
		res+=L[0];
	cout<<res<<endl;
	return 0;
}


/*

*/