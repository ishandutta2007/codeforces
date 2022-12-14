#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;
int a[200005];
map<int,int> s;
signed main()
{
	ios;
	int n; cin>>n;
	int maxn = -1 , sum = 0 , ans = 0, x;
	s[0] = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		if(s.count(sum)) maxn = max(maxn,s[sum]);
		ans += i-maxn-1;
		s[sum] = i;
	}
	cout<<ans<<endl;

}