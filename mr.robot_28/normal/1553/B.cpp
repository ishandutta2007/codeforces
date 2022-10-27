#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt_t;
    cin >> cnt_t;
    while(cnt_t--)
    {
        string a;
        string b;
        cin >> a >> b;
        vector <bool> can1(sz(b)), can2(sz(b));
        for(int i = 0; i < sz(a); i++)
        {
            for(int t =0; t + i < sz(a) && t <sz(b); t++)
            {
                if(a[i + t] != b[t]){
                    break;
                }
                can1[t] = 1;
            }
            for(int t =0; i + t < sz(a) && t < sz(b); t++)
            {
                if(a[i + t] != b[sz(b) - t - 1])
                {
                    break;
                }
                can2[sz(b) - t - 1] = 1;
            }
        }
        bool ans = 0;
        for(int i = 0; i < sz(b); i++)
        {
            bool fl = 1;
            int u = min(i, sz(b) - i - 1);
            for(int k = 0; k < u; k++)
            {
                if(b[i - k - 1] != b[i + 1 + k])
                {
                    fl = 0;
                }
            }
     //       cout << fl << " ";
            if(!fl)
            {
                continue;
            }
            if(can1[i] && u == sz(b) - i - 1)
            {
                ans = 1;
            }
            if(u == i && can2[i])
            {
                ans = 1;
            }
        }
        if(ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}