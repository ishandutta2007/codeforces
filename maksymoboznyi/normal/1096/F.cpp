#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;
const long long M = 998244353;

int n, p[N], t[N], pp[N];
long long ans = 0;
vector<int> v;
bool used[N];

long long gp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 0) {
            a *= a;
            a %= M;
            b /= 2;
        } else {
            b--;
            res *= a;
            res %= M;
        }
    }
    return res;
}

void merge(int l, int r) {
    if (l >= r)
        return;
    int m = (l + r) / 2;
    merge(l, m);
    merge(m + 1, r);
    int i = l, j = m + 1;
    int cur = l;
    while (i <= m && j <= r)
    {
        if (pp[i] < pp[j])
            t[cur] = pp[i], cur++, i++;
        else
            t[cur] = pp[j], cur++, ans += (m - i + 1), j++;
    }
    while (i <= m)
        t[cur] = pp[i], i++, cur++;
    while (j <= r)
        t[cur] = pp[j], j++, cur++;
    for (int i = l; i <= r; i++)
        pp[i] = t[i];
}

signed main()
{
    cin >> n;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != -1)
            used[p[i]] = 1;
        else
            cnt++;
    }
    if (cnt == 0) {
        for (int i = 1; i <= n; i++)
            pp[i] = p[i];
        merge(1, n);
        cout << ans % M;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            v.pb(i);
    long long P = 0, q = 4*cnt;
    ///case1
    P += cnt * (cnt - 1) * cnt;
    P %= M;
    ///case2
    long long cur = 0;
    for (int i = 1; i <= n; i++)
        if (p[i] == -1)
            cur++;
        else {
            long long kol = upper_bound(v.begin(), v.end(), p[i]) - v.begin();
            kol = v.size() - kol;
            P += 4 * kol * cur;
            //cout << kol << ' ' << cur << endl;
            P %= M;
        }
    ///case3
    cur = 0;
    for (int i = n; i > 0; i--)
        if (p[i] == -1)
            cur++;
        else {
            long long kol = lower_bound(v.begin(), v.end(), p[i]) - v.begin();
            P += 4 * kol * cur;
            P %= M;
        }
    ///case4
    cur = 1;
    for (int i = 1; i <= n; i++)
        if (p[i] != -1)
            pp[cur] = p[i], cur++;
    merge(1, cur - 1);
    //ans << endl;
    P += ans * 4 * cnt;
    //cout << P << ' ' << q;
    P %= M;
    //q = 2   , P = 1;
    cout << P * gp(q, M - 2) % M;
    return 0;
}