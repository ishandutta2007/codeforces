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
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MOD=1000000007;

int n,k;
int a[1<<24],v[2],F[1<<24],s[1<<24];

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>a[1<<i];
	cin>>k;
	for (int i=0;i<k;++i)
		cin>>v[i];
	F[0]=1;
	for (int i=0;i<1<<n;++i)
	{
		s[i]=s[i-(i&-i)]+a[i&-i];
		if (s[i]>MOD) s[i]=MOD;
		if (s[i]==v[0]||s[i]==v[1]) continue;
		for (int j=i;j;j-=j&-j)
		{
			F[i]+=F[i-(j&-j)];
			if (F[i]>=MOD) F[i]-=MOD;
		}
	}
	cout<<F[(1<<n)-1]<<endl;
	return 0;
}