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

int n,ans;
int u[100010];

int main()
{
	string s;
	cin>>s;
	n=s.size();
	for (int i=0;i<n;++i)
		if (s.substr(i,4)=="bear")
			u[i+1]=1;
	for (int i=1;i<=n;++i)
		u[i]+=u[i-1];
	for (int i=1;i<=n-3;++i)
		for (int j=i;j<=n-3;++j)
			if (u[j]-u[i-1]) ans++;
	cout<<ans<<endl;
	return 0;
}