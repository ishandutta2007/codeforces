#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
int n, q;
string s, t;
int m;
string s1 = "";
const int N = 1e6 + 1;
int post[N][26];
int power[N], power_1[N];
int power1[N], power2[N];
vector <pair <int, int> > hash0, hash1;
int power_all(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        int t = power_all(a, b / 2);
        return 1LL * t * t % mod1;
    }
    return 1LL * a * power_all(a, b - 1) % mod1;
}
pair <int, int> get_hash(int l, int r)
{
    if(l == 0)
    {
        return hash0[r];
    }
    else
    {
        return {(hash0[r].first - 1LL * hash0[l - 1].first * power1[r - l + 1] % mod1 + mod1) % mod1,
        (hash0[r].second - 1LL * hash0[l - 1].second * power2[r - l + 1] % mod2 + mod2) % mod2};
    }
}
pair <int, int> get_hash1(int l, int r)
{
    if(l == 0)
    {
        return hash1[r];
    }
    else
    {
        return {(hash1[r].first - 1LL * hash1[l - 1].first * power1[r - l + 1] % mod1 + mod1) % mod1,
        (hash1[r].second - 1LL * hash1[l - 1].second * power2[r - l + 1] % mod2 + mod2) % mod2};
    }
}
void relax(int &a)
{
    if(a >= mod1)
    {
        a -= mod1;
    }
    if(a < 0)
    {
        a += mod1;
    }
}
int sum(int l, int r, int a)
{
    if(l == 0)
    {
        return post[r][a];
    }
    return (post[r][a] - post[l - 1][a] + mod1) % mod1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    cin >> s >> t;
    power[0] = 1;
    power1[0] = power2[0] = 1;
    for(int i = 1; i < N; i++)
    {
        power1[i] = 1LL * power1[i - 1] * 27 % mod1;
        power2[i] = 1LL * power2[i - 1] * 27 % mod2;
        power[i] = 1LL * power[i - 1] * 2 % mod1;
    }
    power_1[N - 1] = power_all(power[N - 1], mod1 - 2);
    for(int i = N - 2; i >= 0; i--)
    {
        power_1[i] = 1LL * 2 * power_1[i + 1] % mod1;
    }
    for(int i = 0; i < t.size(); i++)
    {
        for(int j = 0; j < 26; j++)
        {
            int val = 0;
            if(i != 0)
            {
                val = post[i - 1][j];
            }
            post[i][j] = (val + ((j + 'a') == t[i]) * power[t.size() - 1 - i]) % mod1;
        }
    }
    string s1;
    while(q--)
    {
        int k;
        string w;
        cin >> k >> w;
        hash0.resize(w.size());
        for(int i = 0; i < w.size(); i++)
        {
            if(i == 0)
            {
                hash0[i].first = hash0[i].second = w[i] - 'a' + 1;
            }
            else
            {
                hash0[i].first = (1LL * hash0[i - 1].first * 27 + w[i] - 'a' + 1) % mod1;
                hash0[i].second = (1LL * hash0[i - 1].second * 27 + w[i] - 'a' + 1) % mod2;
            }
        }
        int ans = 0;
        s1 = s;
        int it = 0;
        while(it < k && s1.size() < w.size())
        {
            s1 = s1 + t[it] + s1;
            it++;
        }
        int m = s1.size();
        hash1.resize(s1.size());
        for(int i = 0; i < s1.size(); i++)
        {
            if(i == 0)
            {
                hash1[i].first = hash1[i].second = s1[i] - 'a' + 1;
            }
            else
            {
                hash1[i].first = (1LL * hash1[i - 1].first * 27 + s1[i] - 'a' + 1) % mod1;
                hash1[i].second = (1LL * hash1[i - 1].second * 27 + s1[i] - 'a' + 1) % mod2;
            }
        }
        int m1 = w.size();
        if(s1.size() >= w.size())
        {
            for(int i = 0; i <= s1.size() - w.size(); i++)
            {
                if(get_hash(0, w.size() - 1) == get_hash1(i, i + w.size() - 1))
                {
                    ans++;
                }
            }
            vector <int> cnt_t(26);
            ans = 1LL * ans * power[k - it] % mod1;
            for(int i = 0; i < m1; i++)
            {
                if((i == 0 || get_hash1(m - i, m - 1) == get_hash(0, i - 1)) &&
                   (i == m1 - 1 || get_hash1(0, (m1 - 2) - i) == get_hash(i + 1, m1 - 1)))
                {
                    cnt_t[w[i] - 'a']++;
                }
            }
            if(it < k)
            {
            for(int i = 0; i < 26; i++)
            {
                ans = (ans + 1LL * cnt_t[i] * sum(it, k - 1, i) % mod1 * power_1[n - k]) % mod1;
            }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}