#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1005;
ll x[maxN], y[maxN];
ll det(int i, int j, int k) {
    return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
}
ll askArea(int i, int j, int k) {
#ifdef DEBUG
    return abs(det(i, j, k));
#endif
    cout << 1 << " " << i << " " << j << " " << k << endl;
    ll resp;
    cin >> resp;
    return resp;
}
int askVec(int i, int j, int k) {
#ifdef DEBUG
    if (det(i, j, k) > 0) return 1;
    else return -1;
#endif
    cout << 2 << " " << i << " " << j << " " << k << endl;
    int res;
    cin >> res;
    return res;
}
int n;
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
#ifdef DEBUG
x[1] = 0;
y[1] = 0;
x[2] = 0;
y[2] = 1;
x[3] = 1;
y[3] = 1;
x[4] = 1;
y[4] = 0;
#endif
    cin >> n;
    int who = n;
    vector < int > up, down;
    for (int i = 2; i < n; i++) {
        if (askVec(1, i, who) < 0) {
            up.emplace_back(i);
        }
        else {
            down.emplace_back(i);
        }
    }
    // solve up
    vector < pair < ll, int > > get_vals;
    for (int v : up) {
        get_vals.emplace_back(askArea(1, v, who), v);
    }
    sort(get_vals.begin(), get_vals.end());
    reverse(get_vals.begin(), get_vals.end());
    deque < int > ans_up;
    if (!get_vals.empty()) ans_up.push_back(get_vals[0].second);
    for (int i = 1; i < get_vals.size(); i++) {
        int p = get_vals[i].second;
        if (askVec(1, p, ans_up.front()) < 0) ans_up.push_front(p);
        else ans_up.push_back(p);
    }
    vector < int > perm;
    for (int v : ans_up) perm.push_back(v);
    perm.push_back(who);
    // solve down
    get_vals.clear();
    deque < int > ans_down;
    for (int v : down) {
        get_vals.emplace_back(askArea(1, v, who), v);
    }
    sort(get_vals.begin(), get_vals.end());
    reverse(get_vals.begin(), get_vals.end());
    if (!get_vals.empty()) ans_down.push_back(get_vals[0].second);
    for (int i = 1; i < get_vals.size(); i++) {
        int p = get_vals[i].second;
        if (askVec(1, p, ans_down.front()) < 0) ans_down.push_front(p);
        else ans_down.push_back(p);
    }
    for (int v : ans_down) perm.push_back(v);
    reverse(perm.begin(), perm.end());
    cout << 0 << " ";
    cout << 1 << " ";
    for (int v : perm) cout << v << " ";
    cout << endl;
    return 0;
}