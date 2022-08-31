#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MOD=1000000007;
const int MaxN=2010;

int n,k,ans;
int F[MaxN][MaxN];

int main()
{
	cin>>n>>k;
	F[0][1]=1;
	for (int i=0;i<k;++i)
		for (int j=1;j<=n;++j)
		{
			for (int p=j;p<=n;p+=j)
				(F[i+1][p]+=F[i][j])%=MOD;
		}
	for (int i=1;i<=n;++i)
		(ans+=F[k][i])%=MOD;
	cout<<ans<<endl;
	return 0;
}