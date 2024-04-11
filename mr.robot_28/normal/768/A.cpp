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
    for(int i= 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        if(a[i] > a[0] && a[i] < a[n - 1])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}