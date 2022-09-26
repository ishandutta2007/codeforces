#include<bits/stdc++.h>
using namespace std;
#define int	long long
const int N	= 1e5 + 5;
signed main()	{
	ios_base::sync_with_stdio(false);	cin.tie(0);
	int n, x[N];
	cin >> n;
	for(int i = 1 ; i <= n ; ++i)cin >> x[i];
	sort(x + 1, x + 1 + n);
	int cur = x[n], sum = 0;
	int cnt[3];
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i = 1 ; i <= n ; ++i)	{
		x[i] = cur - x[i];
		sum += x[i];
		cnt[x[i]]++;
	}
	int mn = x[n], mx = x[1];
	if(mn + 1 >= mx)	{
		cout << n <<"\n";
		for(int i = 1 ; i <= n ; ++i)	cout << cur - x[i] << " ";
		return 0;
	}
	int ans = INT_MAX;
	int a0 , a1 , a2;
	for(int i = 0 ; i <= n ; ++i)	{
		int j = sum - n + i;
		int k = sum - 2 * j;
		if(j < 0 || k < 0 || j > n || k > n)	continue;
		int num = min(i,cnt[0]) + min(j,cnt[2]) + min(k,cnt[1]);
		if(num < ans)	{
			ans = num;
			a0 = i ;
			a1 = k;
			a2 = j;     //nam sinh ha noi
		}
	}
	cout << ans <<"\n";
	for(int i = 1 ; i <= a0 ; ++i)	cout << cur <<" ";
	for(int i = 1 ; i <= a1 ; ++i)	cout << cur - 1 <<" ";
	for(int i = 1 ; i <= a2 ; ++i)	cout << cur - 2 <<" ";
}