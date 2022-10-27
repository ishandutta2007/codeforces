
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> cnt(n);
        int max1 =0 ;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
            cnt[a[i]]++;
            max1 = max(max1, cnt[a[i]]);
        }
        if(max1 > (n + 1) / 2)
        {
            cout << -1 << "\n";
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            cnt[i] = 0;
        }
        int ans = 0;
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            int j = i;
            while(j + 1 < n && a[j + 1] != a[j])
            {
                j++;
            }
            cnt[a[i]]++;
            cnt[a[j]]++;
            i = j;
            k++;
        }
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, cnt[i] - k - 1);
        }
        cout << ans + k - 1 << "\n";
    }
    return 0;
}