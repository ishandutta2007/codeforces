#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int n, l, x, y, a[MAXN];
set<int> st;
bool b1, b2;

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> l >> x >> y;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i=0; i<n; i++) {
        if (st.count(a[i]-x)) b1 = 1;
        if (st.count(a[i]-y)) b2 = 1;
    }

    if (b1 && b2) {
        cout << 0;
        return 0;
    } else if (b2) {
        cout << 1 << '\n' << x;
        return 0;
    } else if (b1) {
        cout << 1 << '\n' << y;
        return 0;
    }

    for (int i=0; i<n; i++) {
        int k = a[i]-x;
        if (k>=0 && k<=l && (st.count(k-y) || st.count(k+y))) {
            cout << 1 << '\n' << k;
            return 0;
        }

        k = a[i]+x;
        if (k>=0 && k<=l && (st.count(k-y) || st.count(k+y))) {
            cout << 1 << '\n' << k;
            return 0;
        }
    }

    cout << 2 << '\n' << x << ' ' << y;
    return 0;
}