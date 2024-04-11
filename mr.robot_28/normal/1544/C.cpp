#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 2e6;

signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        vector <int> prefa(n + 1), prefb(n + 1);
        for(int i = 1; i <= n; i++)
        {
            prefa[i] = prefa[i - 1] + a[i - 1];
            prefb[i] = prefb[i - 1] + b[i - 1];
        }
        int l = -1, r = 1e9;
        while(r - l > 1)
        {
            int midd = (r + l) / 2;
            int k = (midd + n) / 4;
            int u1 = 0, u2 = 0;
            if(k <= n)
            {
                u1 = midd * 100 + prefa[n] - prefa[k];
            }
            else
            {
                u1 = (midd - (k - n)) * 100;
            }
            if(k <= midd)
            {
                u2 = prefb[n];
            }
            else
            {
                k -= (midd);
                u2 = prefb[n - k];
            }
            if(u1 >= u2)
            {
                r = midd;
            }
            else
            {
                l = midd;
            }
        }
        cout << r << "\n";
    }
    return 0;
}