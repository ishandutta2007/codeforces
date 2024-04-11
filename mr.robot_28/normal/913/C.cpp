#include<bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, L;
    cin >> n >> L;
    vector <long long> c(n);
    long long cnt1 = 1e9;
    long long ans =0 ;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        cnt1= min(cnt1 * 2, c[i]);
        if((1LL << i) & L)
        {
            ans += cnt1;
        }
        else{
            ans = min(ans, cnt1);
        }
    }
    int t = log2(L) + 1;
    for(int i = n; i <= t ;i++)
    {
        cnt1 = cnt1 * 2;
        if((1LL << i) & L)
        {
            ans += cnt1;
        }
        else
        {
            ans = min(ans, cnt1);
        }
    }
    cout << ans;
    return 0;
}