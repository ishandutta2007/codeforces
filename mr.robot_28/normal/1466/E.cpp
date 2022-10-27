#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
int n;
const int N = 5e5;
int x[N];
const int mod = 1e9 + 7;
void relax(int &a)
{
    if(a >= mod)
    {
        a -= mod;
    }
    if(a < 0)
    {
        a += mod;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector <int> cnt(60, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
            int x1 = x[i];
            int it = 0;
            while(x1 > 0)
            {
                cnt[it] += (x1 & 1);
                x1 = x1 / 2;
                it++;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            for(int j = 0; j < 60; j++)
            {
                if(x[i] & (1LL << j))
                {
                    sum1 += n * ((1LL << j) % mod) % mod;
                    relax(sum1);
                }
                else
                {
                    sum1 += cnt[j] * ((1LL << j) % mod) % mod;
                    relax(sum1);
                }
            }
            for(int j = 0; j < 60; j++)
            {
                if(x[i] & (1LL << j))
                {
                    sum2 += cnt[j] * ((1LL << j) % mod) % mod;
                    relax(sum2);
                }
            }
            ans += sum1 * sum2 % mod;
            relax(ans);
        }
        cout << ans << "\n";
    }
    return 0;
}