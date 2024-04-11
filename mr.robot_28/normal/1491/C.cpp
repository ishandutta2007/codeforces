#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define sz(a) (int)a.size()
#define X first
#define Y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> s(n);
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        vector <int> add(n + 1);
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            //cout << sum << " ";
            int k = max(0LL, s[i] - sum - 1);
            ans += k;
            add[i + 1] -= max(0LL, sum + k - s[i] + 1);
            sum += max(0LL, sum + k - s[i] + 1);
            if(i != 0)
            {
                sum += (s[i - 1] != 1);
            }
            add[min(n, i + s[i])] -= (s[i] != 1);
            sum += add[i];
        }
        cout <<ans << "\n";
    }
    return 0;
}