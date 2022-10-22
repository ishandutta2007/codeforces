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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& x : p)
        cin >> x;
    int k = n / 2;
    vector<int> c;
    c.reserve(n);
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && p[i] == p[j]) j++;
        c.push_back(j - i);
        i = j - 1;
    }
    int s = n;
    while (s > k) {
        s -= c.back();
        c.pop_back();
    }
    if ((int) c.size() < 3) {
        cout << "0 0 0\n";
        return;
    }
//    for (int x : c) {
//        cout << x << " ";
//    }
    int g = c[0];
    s = 0;
    int b = 0, i = 1;
    while (i < (int) c.size() && s <= g) s += c[i++];
    while (i < (int) c.size()) b += c[i++];
    if (s > g && b > g) {
        cout << g << " " << s << " " << b << "\n";
    } else {
        cout << "0 0 0\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}