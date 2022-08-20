/*
    31.03.2019 23:26:00
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    if (n == 1) {
        for (int i = 0; i < q; ++i) {
            cout << '1';
        }
        cout << '\n';
        return 0;
    }
    vector<int> p(n);
    vector<int> ip(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
        ip[p[i]] = i;
    }
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i] = ip[a[i] - 1];
    }
    // show(a);
    vector<vector<int>> sp(25, vector<int>(m, -1));
    vector<int> lst(n, -1);
    for (int i = 0; i < m; ++i) {
        lst[a[i]] = i;
        if (a[i] == 0) sp[0][i] = lst[n - 1];
        else sp[0][i] = lst[a[i] - 1];
    }
    // show(left);
    for (int i = 1; i < 25; ++i)
        for (int j = 0; j < m; ++j)
            if (sp[i - 1][j] != -1)
                sp[i][j] = sp[i - 1][sp[i - 1][j]];
    vector<int> shifts;
    int nn = n - 1;
    int ind = 0;
    while (nn != 0) {
        if (nn & 1) {
            shifts.push_back(ind);
        }
        ++ind;
        nn /= 2;
    }
    // show(shifts);
    // show(sp[0], sp[1], sp[2], sp[3]);
    vector<int> left(m, -1);
    for (int i = 1; i < m; ++i) {
        left[i] = left[i - 1];
        int l = i;
        for (auto s : shifts) {
            l = sp[s][l];
            if (l == -1)
                break;
        }
        left[i] = max(left[i], l);
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (left[r] >= l) cout << '1';
        else cout << '0';
    }
    cout << '\n';
    return 0;
}