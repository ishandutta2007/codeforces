#include<bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(n);
    for(int i = 0; i < n;i++)
    {
    	cin >> a[i];
	}
	int ans = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		cnt[a[i]]++;
		if(cnt[a[i]] > 1)
		{
			ans++;
		}
	}
	cout << ans;
    return 0;
}