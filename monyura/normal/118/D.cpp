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
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}


int main()
{
	int n1,n2;
	int k1,k2;
	cin>>n1>>n2;
	cin>>k1>>k2;
	int D[101][101][11][2];
	int Prev[101][101][11][2]={0};
	Prev[0][0][0][0]=1;
	//Prev[0][0][0][1]=1;
	int MOD=1e8;
	int res=0;
	rep(t,1,n1+n2+1)
	{
		memset(D,0,sizeof(D));
		rep(i,0,n1+1)
		{
			rep(j,0,n2+1)
				rep(k,0,11)
				{
					if (k<k1 && i<n1)
						D[i+1][j][k+1][0]=(D[i+1][j][k+1][0]+ Prev[i][j][k][0])%MOD;
					if (i<n1)
						D[i+1][j][1][0]=(D[i+1][j][1][0]+Prev[i][j][k][1])%MOD;
					if (k<k2 && j<n2)
						D[i][j+1][k+1][1]=(D[i][j+1][k+1][1]+Prev[i][j][k][1])%MOD;
					if (j<n2)
						D[i][j+1][1][1]=(D[i][j+1][1][1]+Prev[i][j][k][0])%MOD;
				}
		}
		memcpy(Prev,D,sizeof(D));
	}
	rep(k,1,11)
		rep(t,0,2)
		{
			res=(res+D[n1][n2][k][t])%MOD;	
		}
	printf("%d\n",res);
				
					
	return 0;
}
/*

*/