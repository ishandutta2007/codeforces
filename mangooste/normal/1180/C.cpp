#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &el : a)
        cin >> el;
    deque<int> dq;
    for (int i = 0; i < n; i++)
        dq.pb(a[i]);
    int mx = *max_element(all(a));
    int cnt = 0;
    vector<pii> precalc;
    while (dq.front() != mx) {
        cnt++;
        int A = dq.front();
        dq.pop_front();
        int B = dq.front();
        dq.pop_front();
        precalc.eb(A, B);
        if (A < B)
            swap(A, B);
        dq.pb(B);
        dq.push_front(A);
    }
    vector<int> b;
    for (int i = 1; i < n; i++)
        b.pb(dq[i]);
    // cerr << "b = ";
    // for (auto el : b)
    //     cerr << el << ' ';
    // cerr << endl;
    // cerr << "cnt = " << cnt << endl;
    for (int tt = 0; tt < q; tt++) {
        ll x;
        cin >> x;
        if (x <= cnt) {
            cout << precalc[x - 1].first << ' ' << precalc[x - 1].second << '\n';
            continue;
        }
        x -= cnt + 1;
        x %= n - 1;
        cout << mx << ' ' << b[x] << '\n';
    }
}