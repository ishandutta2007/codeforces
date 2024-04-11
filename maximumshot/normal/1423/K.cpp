#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

bool check(int a, int b, int c) {
    int mx = max({a, b, c});
    return mx < a + b + c - mx;
}

const int X = 1e6 + 5;

vector<int> ps;
int d[X];
int pr[X];
int sq[X];

void precalc() {
    fill(d, d + X, -1);
    for (int p = 2; p < X; p++) {
        if (d[p] == -1) {
            d[p] = (int) ps.size();
            ps.push_back(p);
            pr[p] = 1;
        }
        for (int i = 0; i <= d[p] && p * ps[i] < X; i++)
            d[p * ps[i]] = i;
    }
    for (int p = 1; p < X; p++)
        pr[p] += pr[p - 1];
    sq[0] = 1;
    for (int i = 1; i < X; i++) {
        sq[i] = sq[i - 1];
        while (sq[i] * sq[i] <= i)
            sq[i]++;
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 0;
        if (sq[n] <= n)
            res += pr[n] - pr[sq[n] - 1];
        if (sq[n] > n || 1 < sq[n])
            res++;
        cout << res << "\n";
    }

    return 0;
}