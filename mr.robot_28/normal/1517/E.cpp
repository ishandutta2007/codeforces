#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
const int mod = 998244353;
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
        int n;
        cin >> n;
        int s = 0;
        vector <int> a(n);
        vector <int> pref(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
            s += a[i];
        }
        int s1 = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            s1 += a[i];
            if(s1 * 2 >  s)
            {
                ans++;
            }
        }
    //    cout << -1 << " " << ans << "\n";
        for(int msk = 0; msk < 4; msk++)
        {
            int u = 0;
            int f1 = (msk & 1);
            int f2 = (msk & 2) >> 1;
            if(f1)
            {
                u += a[0];
            }
            if(f2)
            {
                u += a[n - 1];
            }
            int j = 1 + ((n - f2 - 3) / 2) * 2;
         //   cout << j << "\n";
            for(int t = 1; t <= j; t += 2)
            {
                u += a[t];
            }
            for(int i = 1; i < n - f2 - 1; i += 2)
            {
                if(j < i)
                {
                    break;
                }
                while(j - 2 >= i && u * 2 >= s1)
                {
                    u -= a[j];
                    j -= 2;
                }
                if(u * 2 < s1)
                {
                    ans += ((j - i) / 2 + 1);
                }
                else
                {
                    break;
                }
                u += a[i + 1];
            }
      //      cout << msk << " " << ans << "\n";
            u = 0;
            if(f1)
            {
                u += a[0];
            }
            if(f2)
            {
                u += a[n - 1];
            }
            int st = 2 * (1 - f1);
            j = st + ((n - st - f2 - 2) / 2) * 2;
     //       cout << j << "\n";
            if(st > 0)
            {
                u += a[1];
            }
            for(int t = 2; t <= j; t += 2)
            {
                u += a[t];
            }
            for(int i = st; i < n - f2 - 1; i += 2)
            {
                if(j < i)
                {
                    break;
                }
                while(j - 2 >= i && u * 2 >= s1)
                {
                    u -= a[j];
                    j -= 2;
                }
                if(u * 2 < s1)
                {
                    ans += (j - i) / 2 + 1;
                }
                else
                {
                    break;
                }
                u += a[i + 1];
            }
        //    cout << f1 << " " << f2 << " " << msk << " " << ans << "\n";
        }
        cout << ans % mod << "\n";
    }
    return 0;
}