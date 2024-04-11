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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 1) a.push_back(1);
            else {
                while (!a.empty() && a.back() != x - 1) a.pop_back();
                assert(!a.empty());
                a.back()++;
            }
            cout << a[0];
            for (int i = 1; i < a.size(); ++i) cout << '.' << a[i];
            cout << '\n';
        }
    }
    return 0;
}