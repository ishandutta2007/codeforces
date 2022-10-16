#include <iostream>
#include <numeric>
#define v1 l, (l + r) / 2, 2 * v + 1
#define v2 (l + r) / 2, r, 2 * v + 2
#define N 100001

using namespace std;

//const long long q = 1, mod = (int64_t)1000000 * 1000000 + 39, m = 1000000007;
const long long q = 1000003, mod = (int64_t)1000000 * 1000000 + 61, m = 1000000007;

//long long ans1[N], ans0[N], sans0[N];
long long ans[N], sans[N];
long long hsh[N], thsh, qt = 1;
int ne[N];

//long long set(int l, int r, int v, int x, int m)
//{
//    if (l > x || r <= x)
//        return 0;
//    if (r == l + 1)
//        return ans1[v] = m;
//    return ans1[v] = (set(v1, x, m) + set(v2, x, m)) % ::m;
//}
//
//long long sum(int l, int r, int v, int L, int R)
//{
//    if (l >= R || L >= r)
//        return 0;
//    if (l >= L && r <= R)
//        return ans1[v];
//    return (sum(v1, L, R) + sum(v2, L, R)) % m;
//}

string s, t;
int main()
{
    cin >> s;
    cin >> t;
    if (s.size() <= t.size())
    {
        cout << (s == t);
        return 0;
    }

    for (int i = 0; i < t.size(); ++i)
        hsh[0] = (hsh[0] * q + s[i]) % mod, qt = (qt * q) % mod, thsh = (thsh * q + t[i]) % mod;
    for (int i = 1; i <= s.size() - t.size(); ++i)
        hsh[i] = ((hsh[i - 1] * q + s[t.size() + i - 1] - s[i - 1] * qt) % mod + mod) % mod;

    for (int i = s.size() - t.size(); i >= 0; --i)
        if (hsh[i] == thsh)
            ne[i] = i + t.size();
        else if (ne[i + 1] != 0)
            ne[i] = ne[i + 1];

//    ans0[s.size()] = 1;
//    ans0[s.size() - 1] = sans0[s.size() - 1] = 2;
//    for (int i = s.size() - 2; i >= 0; --i)
//    {
//        ans0[i] = (ans0[i + 1] + sans0[i + 1]) % m;
//        sans0[i] = (ans0[i] + sans0[i + 1]) % m;
////        set0(0, s.size(), 0, i, (sum0(0, s.size(), 0, i + 1, i + 2) + sum0(0, s.size(), 0, i + 1, s.size())) % m);
//    }
//    set(0, s.size(), 0, s.size() - 1, (hsh[s.size() - 1] == thsh));
//    for (int i = s.size() - 2; i >= 0; --i)
//        if (ne[i])
//            set(0, s.size(), 0, i, (sum(0, s.size(), 0, i + 1, i + 2) + sum(0, s.size(), 0, i + 1, ne[i]) + 1) % m);
//    cout << sum(0, s.size(), 0, 0, s.size());
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (ne[i])
            ans[i] = (ans[i + 1] + sans[ne[i]] + s.size() - ne[i] + 1) % m;
        sans[i] = (sans[i + 1] + ans[i]) % m;
    }
//    cout << accumulate(ans, ans + s.size(), 0);
    cout << ans[0];
    return 0;
}