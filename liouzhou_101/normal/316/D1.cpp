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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MOD=1000000007;
const int MaxN=1000100;

int n;
int u[3];
ll F[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		++u[x];
	}
	ll t=0;
	F[0]=F[1]=1;
	for (int i=2;i<=u[1];++i)
	{
		(t+=F[i-2]*(i-1))%=MOD;
		F[i]=(t+1)%MOD;
	}
	ll ans=F[u[1]];
	for (int i=1;i<=u[2];++i)
		(ans*=n-i+1)%=MOD;
	cout<<ans<<endl;
	return 0;
}