#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

ll n, SS;

ll sum(ll a) {
    return 1LL * a * (a + 1) / 2;
}

ll sum(ll a, ll b) {
    ll res = sum(b);
    if (a > 0) {
        res -= sum(a - 1);
    }
    return res;
}

int pr[max_n];
int d[max_n];
vector<int> v[max_n];

ll get_mins(int r) {
    d[0] = 1;
    ll sum = 1;
    for (int i = 1; i < n; ++i) {
        pr[i] = (i - 1) / r;
        d[i] = d[pr[i]] + 1;
        sum += d[i];
    }
    return sum;
}

void build(int r) {
    v[1].PB(0);
    d[0] = 1;
    ll sum = 1;
    int mxd = -1;
    for (int i = 1; i < n; ++i) {
        pr[i] = (i - 1) / r;
        d[i] = d[pr[i]] + 1;
        sum += d[i];
        v[d[i]].PB(i);
        mxd = max(mxd, d[i]);
    }
    int lst = mxd;
    ll s = SS - sum;
    if (s < 0) {
        exit(228);
    }
    while(true) {
        if (v[mxd].size() == 1) {
            --mxd;
            continue;
        }
        int cur = v[mxd].back();
        v[mxd].pop_back();
        if (lst + 1 - d[cur] <= s) {
            s += d[cur];
            d[cur] = lst + 1;
            s -= d[cur];
            pr[cur] = v[lst][0];
            ++lst;
            v[lst].PB(cur);
        } else {
            if (s == 0) break;
            pr[cur] = v[mxd + s - 1][0];
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << pr[i] + 1 << ' ';
    }
    cout << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> SS;
    if (sum(n) < SS) {
        cout << "No" << endl;
        return 0;
    }
    if (1 + 2 * (n - 1) > SS) {
        cout << "No" << endl;
        return 0;
    }
    if (sum(n) == SS) {
        cout << "Yes" << endl;
        for (int i = 1; i < n; ++i) {
            cout << i << "\n";
        }
        return 0;
    }
    ll min_ans = inf;
    // l ne podhodit, r - podhodit
    int l = 1, r = n - 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (get_mins(mid) > SS) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << "Yes" << endl;
    // 14:34
    // 15:03
    build(r);
    return 0;
}