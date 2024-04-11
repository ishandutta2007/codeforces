#include <bits/stdc++.h>

using namespace std;

int n;
int a[300005], b[300005];
vector <int> l, r;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] < b[i]) l.push_back(i);
        else r.push_back(i);
    }
    if (l.size() >= r.size()) {
        sort(l.begin(), l.end(), [](int x, int y) {
                return b[x] > b[y];
             });
        cout << l.size() << endl;
        for (auto x: l) cout << x << ' '; cout << endl;
    }
    else {
        sort(r.begin(), r.end(), [](int x, int y) {
                return a[x] < a[y];
             });
        cout << r.size() << endl;
        for (auto x: r) cout << x << ' '; cout << endl;
    }
    return 0;
}