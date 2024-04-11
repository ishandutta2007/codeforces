#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
const int LIM = 62;
int dp[LIM + 10][N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector <int> b(n);
    for(int i = 0; i < n; i++){
        b[i]= a[n - 1] - a[i];
    }
    for(int i = 0; i <= LIM + 4; i++)
    {
        for(int j = 0; j < N; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    vector <int> f;
    for(int i = 0; i < n; i++)
    {
        f.push_back(i);
    }
    for(int bit = 0; bit <= LIM; bit++)
    {
        if(bit != 0)
        {
            vector <int> nf;
            for(auto v : f)
            {
                if(!(b[v] & ((1LL << (bit - 1)))))
                {
                    nf.push_back(v);
                }
            }
            for(auto v : f)
            {
                if((b[v] & (1LL << (bit - 1))))
                {
                    nf.push_back(v);
                }
            }
            f = nf;
        }
        vector <int> prefones(n + 1), prefzeroes(n + 1);
        for(int i =1; i <= n; i++)
        {
            prefones[i] = prefones[i - 1];
            prefzeroes[i] = prefzeroes[i - 1];
            if((1LL << (bit)) & b[f[i - 1]])
            {
                prefones[i]++;
            }
            else
            {
                prefzeroes[i]++;
            }
        }
        int total_0 = prefzeroes[n];
        int total_1 = prefones[n];
        for(int j = 0; j <= n; j++)
        {
            for(int bt = 0; bt < 2; bt++)
            {
                if(dp[bit][j] == 1e9)
                {
                    continue;
                }
                if(bt == 0)
                {
                    int num_ones = (total_0 - prefzeroes[n - j]) + prefones[n - j];
                    int carry_ones = (total_1 - prefones[n - j]);
                    dp[bit + 1][carry_ones] = min(dp[bit + 1][carry_ones], dp[bit][j] + num_ones); 
                }
                else
                {
                    int num_ones = (total_1 - prefones[n - j]) + prefzeroes[n - j];
                    int carry_ones = n - prefzeroes[n - j];
                    dp[bit + 1][carry_ones] = min(dp[bit + 1][carry_ones], dp[bit][j] + num_ones);
                }
            }
        }
    }
  //  cout << dp[1][0] << " " << dp[2][2] << " " << dp[6][0] << "\n";
    int ans = dp[LIM + 1][0];
    cout << ans;
    return 0;
}