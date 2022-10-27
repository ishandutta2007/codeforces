#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(100);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    int maxt = 0;
    int c1 = 1;
    for(int i = 1; i < 100; i++)
    {
        if(cnt[i] > cnt[maxt])
        {
            maxt = i;
            c1 = 1;
        }
        else if(cnt[i] == cnt[maxt])
        {
            c1++;
        }
    }
    if(c1 >= 2)
    {
        cout << n;
        return 0;
    }
    int ans = 0;
    int dp[n * 2 + 1];
    for(int a1 = 0; a1 < 100; a1++)
    {
        if(a1 == maxt)
        {
            continue;
        }
        for(int i = 0; i <= 2 * n; i++)
        {
            dp[i] = 1e9;
        }
        int bal = 0;
        dp[n] = -1;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == maxt)
            {
                bal++;
            }
            else if(a[i]== a1)
            {
                bal--;
            }
            ans = max(ans, i - dp[n + bal]);
            dp[n + bal] = min(dp[n + bal], i);
        }
    }
    cout << ans;
	return 0;
}