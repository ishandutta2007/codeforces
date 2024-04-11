#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector <int> k(n);
        for(int i = 0; i < n; i++)
        {
            cin>> k[i];
            k[i]--;
        }
        sort(k.begin(), k.end());
        int it = 0;
        long long ans = 1e18;
        vector <int> c(m);
        for(int i = 0; i < m; i++)
        {
            cin >> c[i];
        }
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            if(it == n)
            {
                break;
            }
            if(k[it] <= i)
            {

            }
            else
            {
                cnt++;
                it++;
            }
        }
        vector <long long> pref(n);
        for(int i = 0; i < n; i++)
        {
            pref[i] = c[k[i]];
            if(i != 0)
            {
                pref[i] += pref[i - 1];
            }
        }
        long long sum1 = 0;
        for(int i = 0; i <= min(m, n); i++)
        {
            long long t = 0;
            if(i != n)
            {
                t = pref[n - i - 1];
            }
            //cout << t << " ";
            ans = min(ans, t + sum1);
            if(i < m)
            {
                sum1 += c[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}