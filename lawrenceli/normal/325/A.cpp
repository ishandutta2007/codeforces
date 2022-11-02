#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10;

int n, x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
int x3 = 1e9, x4 = -1e9, y3 = 1e9, y4 = -1e9;

void check2(int x, int y) {
    if (x < x3 || x > x4 || y < y3 || y > y4) return;
    bool good = 0;
    rep(i, n)
        if (x1[i] <= x && x <= x2[i] && y1[i] <= y && y <= y2[i])
            good = 1;
    if (!good) {
        cout << "NO\n";
        exit(0);
    }
}

void check(int i) {
    for (int j=x1[i]; j<=x2[i]; j++)
        for (int dx=-1; dx<=1; dx++)
            for (int dy=-1; dy<=1; dy++)
                check2(j+dx, y1[i]+dy), check2(j+dx, y2[i]+dy);

    for (int j=y1[i]; j<=y2[i]; j++)
        for (int dx=-1; dx<=1; dx++)
            for (int dy=-1; dy<=1; dy++)
                check2(x1[i]+dx, j+dy), check2(x2[i]+dx, j+dy);
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i]<<=1, y1[i]<<=1, x2[i]<<=1, y2[i]<<=1;
        x3 = min(x3, x1[i]);
        x4 = max(x4, x2[i]);
        y3 = min(y3, y1[i]);
        y4 = max(y4, y2[i]);
    }

    assert(x3 <= x4);
    assert(y3 <= y4);

    if (x4-x3 != y4-y3) {
        cout << "NO\n";
        return 0;
    }

    rep(i, n) {
        check(i);
    }

    cout << "YES\n";
    return 0;
}