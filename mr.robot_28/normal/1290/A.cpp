#include<bits/stdc++.h> 
using namespace std;
//#define int long long

main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		if(m == 1)
		{
			cout << max(A[0], A[n - 1]) << "\n";
			continue;
		}
		k = min(m - 1, k);
		set <pair <int, int > > p;
		int j = 0;
		int len = n - m + 1;
		while(j + len <= n - k)
		{
			p.insert({max(A[j], A[j + len - 1]), j});
			j++;
		}
		int ans = 0;
		ans = max(ans, p.begin() -> first);
		for(int i = 1; i <= min(k, m - 1); i++)
		{
			p.erase({max(A[i - 1], A[i -1 + len - 1]), i - 1});
			p.insert({max(A[j], A[j + len - 1]), j});
			j++;
			ans = max(ans, p.begin() -> first);
		}
		cout << ans << "\n";
	}
    return 0;
}