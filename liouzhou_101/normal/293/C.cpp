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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

ll n,ans;
vector<ll> v;

int main()
{
	cin>>n;
	if (n%3)
	{
		puts("0");
		return 0;
	}
	n/=3;
	for (ll i=2;i*i<=n;++i)
		if (n%i==0)
		{
			v.push_back(i);
			if (i*i!=n) v.push_back(n/i);
		}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for (int i=0;i<v.size();++i)
	{
		ll p=n/v[i];
		for (int j=0;j<v.size();++j)
		{
			if (p<v[j]) break;
			if (p%v[j]) continue;
			ll q=p/v[j];
			if ((v[i]+v[j]+q)%2==0&&(v[i]+v[j]+q)/2>max(v[max(i,j)],q)) ++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}