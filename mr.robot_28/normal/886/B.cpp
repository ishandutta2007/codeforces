#include<bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    vector <int> a(n);
    vector <int> last(2e5 + 1, -1);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
	}
	int ans;
	for(int i = n - 1; i >= 0; i--)
	{
		if(last[a[i]] == -1)
		{
			ans = a[i];
		}
    	last[a[i]] = i;
	}
	cout << ans;
    return 0;
}