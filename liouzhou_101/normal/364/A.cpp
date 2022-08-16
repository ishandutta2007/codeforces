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

int a;
string s;
int u[400010];
int n;
int p[400010];

int main()
{
	cin>>a>>s;
	n=s.size();
	for (int i=1;i<=n;++i)
		p[i]=s[i-1]-'0';
	for (int i=1;i<=n;++i)
		p[i]+=p[i-1];
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;++j)
		{
			int x=p[j]-p[i-1];
			u[x]++;
		}
	ll ans=0;
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;++j)
		{
			int x=p[j]-p[i-1];
			if (x==0)
			{
				if (a==0) ans+=n*(n+1)/2;
			}
			else
			if (a%x==0)
			{
				x=a/x;
				if (x<=400000) ans+=u[x];
			}
		}
	cout<<ans<<endl;
	return 0;
}