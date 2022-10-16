#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 1; i < n; ++i) if (a[i] <= a[i-1]) ++a[i];
        set<int> s;
        for (auto x: a) s.insert(x);
        cout << s.size() << '\n';
    }
    return 0;
}