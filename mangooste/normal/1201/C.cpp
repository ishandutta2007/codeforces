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
 
#define int __int128
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

istream& operator >> (istream &in, __int128 &a) {
    long long cur;
    in >> cur;
    a = cur;
    return in;
}

ostream& operator << (ostream &out, __int128 a) {
    string cur = "";
    while (a != 0) {
        cur.push_back('0' + a % 10);
        a /= 10;
    }
    if (cur.size() == 0)
        cur.push_back('0');
    reverse(cur.begin(), cur.end());
    out << cur;
    return out;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &el : a)
        cin >> el;
    sort(all(a));
    vector<int> ok;
    for (int i = n / 2; i < n; i++)
        ok.pb(a[i]);

    auto chk = [&](int val) {
        int del = 0;
        for (auto el : ok)
            if (el < val)
                del += val - el;
        return del <= k;
    };

    const int INF = 1e18;
    int L = 0, R = INF;
    while (R - L > 1) {
        int md = (L + R) / 2;
        if (chk(md))
            L = md;
        else
            R = md;
    }
    cout << L << '\n';
}