/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;
// 7
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int N, T, M, P;
int cnt[65] = {0};
string s[200005];
vector<int> v;
gp_hash_table<long long, int, custom_hash> mp[2];
int arr[200005] = {0}, ans = 0, ansmask = 0;

void solve()
{

    cin >> N >> M >> P;
    for (int i = 1; i <= N; i++)
    {
        cin >> s[i];
        for (int j = 0; j < M; j++)
            cnt[j] += (int)s[i][j] - '0';
    }
    for (int j = 0; j < M; j++)
        if (cnt[j] >= (N + 1) / 2)
            v.pb(j);

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < v.size(); j++)
            arr[i] = arr[i] + (1 << j) * (s[i][v[j]] - '0');

    for (int j = 0; j < v.size(); j++)
        mp[1][(1 << j)] = 1;

    for (int i = 1; i <= v.size(); i++)
    {
        if(ans != i - 1)
            break; 
        for (pii j : mp[i % 2])
        {
            if (j.S < i)
                continue;
            int cnt = 0;
            for (int k = 1; k <= N; k++)
                if ((j.F & arr[k]) == j.F)
                    cnt++;
            if (cnt >= (N + 1) / 2)
            {
                ans = i;
                ansmask = j.F;
                
                for (int k = 0; k < v.size(); k++)
                    if (!((1 << k) & j.F))
                        mp[(i + 1) % 2][(1 << k) | j.F]++;
            }
        }
        mp[i % 2].clear();
    }
    string output = string(M, '0');
    for (int k = 0; k < v.size(); k++)
        if (ansmask & (1 << k))
            output[v[k]] = '1';
    cout << output << '\n';
}

signed main()
{
    fast;
    solve();
}