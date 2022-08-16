#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=10010;
const int MaxK=25;

int a[MaxK][MaxN];

void solve(int k,int x,int n)
{
	if (n==1) return;
	int Ln=n-n/2,Rn=n/2;
	solve(k+1,x,Ln);
	solve(k+1,x+Ln,Rn);
	for (int i=x+Ln+1;i<=x+Ln+Rn;++i)
		a[k][i]=x+Ln;
}

int main()
{
	int n,k;
	cin>>n>>k;
	if (n>1) solve(1,0,n-1);
	for (int i=1;i<=k;++i)
	{
		for (int j=1;j<=n;++j)
			printf("%d ",n-a[k-i+1][n-j]);
		puts("");
	}
	return 0;
}