#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int fnd(int l, int r) {
    if (l > r)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    cout << 1 << " " << mid << " " << mid + 1 << "\n";
    cout.flush();
    string s;
    cin >> s;
    if (s == "TAK")
        return fnd(l, mid);
    else
        return fnd(mid + 1, r);
}

int ch(int x, int y) {
    cout << 1 << " " << y << " " << x << "\n";
    cout.flush();
    string s;
    cin >> s;
    if (s == "TAK")
        return 1;
    else
        return 0;
}

int n, k;

int main() {
    cin >> n >> k;
    int x = fnd(1, n);
    int y = fnd(1, x - 1);
    if (y != -1 && ch(x, y)) {
        cout << 2 << " " << x << " " << y << "\n";
        cout.flush();
        return 0;
    }
    y = fnd(x + 1, n);
    if (y != -1 && ch(x, y)) {
        cout << 2 << " " << x << " " << y << "\n";
        cout.flush();
        return 0;
    }
    assert(false);
    return 0;
}