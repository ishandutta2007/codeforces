#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005];
int c[1005];
int ord[1005];
vector <int> ans;

int mex(void) {
    for (int i = 0; ; ++i) if (!c[i]) return i;
}
void change(int i) {
    ans.push_back(i);
    int x = mex();
    --c[a[i]];
    a[i] = x;
    ++c[a[i]];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        ans.clear();
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 0; i <= n; ++i) c[i] = 0;
        for (int i = 1; i <= n; ++i) ++c[a[i]];
        a[0] = mex();
        while (a[0] != n) {
            change(a[0] + 1);
            a[0] = mex();
        }
        for (int i = 1; i <= n; ++i) if (a[i] != i - 1) {
            change(i);
            a[0] = mex();
            while (a[0] != n) {
                change(a[0] + 1);
                a[0] = mex();
            }
        }
        for (int i = 1; i < n; ++i) assert(a[i] < a[i+1]);
        assert(ans.size() <= 2 * n);
        cout << ans.size() << endl;
        for (auto x: ans) cout << x << ' '; cout << endl;
    }
    return 0;
}