#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX (200 * 1000)
int n, k, a, m, x[MAX];

bool input()
{
    cin >> n >> k >> a >> m;
    if (!cin) return false;
    for (int i = 0; i < m; i++) {
        cin >> x[i];
        if (!cin) return false;
    }
    return true;
}

inline int num_ships(int cells)
{
    // find largest x, for which
    // x * a + (x - 1) <= cells
    // x <= (cells + 1) / (a + 1)
    return (cells + 1) / (a + 1);
}

void solve()
{
    set<pii> segments;
    segments.insert(make_pair(1, n));
    int nships = num_ships(n);
    for (int i = 0; i < m; i++) {
        int cursplit = x[i];
        set<pii>::iterator it = segments.upper_bound(make_pair(cursplit, 0));
        if (it == segments.end() || it->first > cursplit) {
            if (it == segments.begin()) {
                continue;
            }
            --it;
        }
        int l = it->first, r = it->second;
        if (l <= cursplit && cursplit <= r) {
            nships -= num_ships(r - l + 1);
            segments.erase(it);
            if (cursplit - l >= a) {
                segments.insert(make_pair(l, cursplit - 1));
                nships += num_ships(cursplit - l);
            }
            if (r - cursplit >= a) {
                segments.insert(make_pair(cursplit + 1, r));
                nships += num_ships(r - cursplit);
            }
            if (nships < k) {
                cout << (i + 1) << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    while (input()) solve();
#else
    input();
    solve();
#endif // LOCAL
    return 0;
}