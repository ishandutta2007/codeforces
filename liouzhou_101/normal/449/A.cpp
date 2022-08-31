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
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	if (n+m-2<k)
	{
		puts("-1");
		return 0;
	}
	k+=2;
	ll pn=sqrt(n),pm=sqrt(m);
	vector<ll> vn;
	for (int i=1;i<=pn;++i)
	{
		vn.push_back(i);
		vn.push_back(n/i+1);
	}
	if (n/pn!=pn) vn.push_back(pn+1);
	
	for (int i=1;i<=pm;++i)
	{
		vn.push_back(k-i);
		vn.push_back(k-m/i);
	}
	sort(vn.begin(),vn.end());
	
	ll ans=0;
	for (auto t : vn)
	{
		if (t>0&&t<=n&&t<k)
		{
			ans=max(ans,(n/t)*(m/(k-t)));
		}
	}
	cout<<ans<<endl;
	return 0;
}