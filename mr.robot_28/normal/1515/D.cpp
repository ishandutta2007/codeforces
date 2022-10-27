#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
const int mod = 1e9 + 7;
const int N = 2e5+ 100;


signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector <int> cnt_l(n), cnt_r(n);
        for(int i = 0; i < l; i++)
        {
            int c;
            cin >> c;
            cnt_l[c - 1]++;
        }
        for(int i = 0; i < r; i++)
        {
            int c;
            cin >> c;
            cnt_r[c - 1]++;
        }
        int u1 = 0, u2 = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int k = min(cnt_l[i], cnt_r[i]);
            cnt_l[i] -= k;
            cnt_r[i] -= k;
            u1 += (cnt_l[i] & 1);
            u2 += (cnt_r[i] & 1);
            cnt_l[i] -= (cnt_l[i] & 1);
            cnt_r[i] -= (cnt_r[i] & 1);
        }
        ans += min(u1, u2);
        u1 -= ans;
        u2 -= ans;
        //cout << u1 << " " << u2 << "\n";
        for(int i = 0; i < n; i++)
        {
            if(u1 > 0)
            {
                int k = min(u1, cnt_r[i]);
                ans += k;
                u1 -= k;
                cnt_r[i] -= k;
            }
            else if(u2 > 0)
            {
                int k = min(u2, cnt_l[i]);
                ans += k;
                u2 -= k;
                cnt_l[i] -= k;
            }
        }
        ans += max(u1, u2);
        for(int i = 0; i < n; i++)
        {
            ans += cnt_l[i] / 2;
            ans += cnt_r[i] / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}