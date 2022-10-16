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
        set<int> s;
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) s.insert(a[i] - a[j]);
        cout << s.size() << '\n';
    }
    return 0;
}