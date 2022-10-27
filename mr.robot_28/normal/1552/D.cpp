#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N =  400;
const int M =  2e5;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        bool fl1 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = abs(a[i]);
            fl1 |= (a[i] == 0);
        }
        if(fl1)
        {
            cout << "YES\n";
            continue;
        }
        vector <int> sums((1 << n));
        for(int msk = 0; msk < (1 << n); msk++)
        {
            for(int i = 0; i < n; i++)
            {
                if((1 << i) & msk)
                {
                    sums[msk] += a[i];
                }
            }
        }
        bool fl = 0;
        for(int msk = 1; msk < (1 << n); msk++)
        {
            int t_msk = (1 << n) - 1 - msk;
            for(int msk1 = t_msk; msk1 > 0; msk1 = (msk1 - 1) & t_msk)
            {
                if(sums[msk] == sums[msk1])
                {
                    fl = 1;
                }
            }
        }
        if(fl)
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