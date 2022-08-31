#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=210;
const int INF=1000000000;

int n;
int a[MaxN];
int F[MaxN][MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=2*n-1;++i)
		cin>>a[i];
	for (int i=0;i<=2*n-1;++i)
		for (int j=0;j<n;++j)
			F[i][j]=-INF;
	F[0][0]=0;
	for (int i=0;i<2*n-1;++i)
		for (int j=0;j<n;++j)
		{
			for (int k=0;k<n*2;++k)
			{
				if (k%2==0)
				{
					F[i+1][(j+k)%n]=max(F[i+1][(j+k)%n],F[i][j]+a[i+1]);
				}
				else
				{
					F[i+1][(j+k)%n]=max(F[i+1][(j+k)%n],F[i][j]-a[i+1]);
				}
			}
		}
	cout<<F[2*n-1][0]<<endl;
	return 0;
}