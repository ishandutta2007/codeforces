#include <bits/stdc++.h>

using namespace std;

int n, k;
map <int, int> cnt;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    n = k + 1;
    for (int i = 1; i <= n; ++i) {
        cout << '?';
        for (int j = 1; j <= n; ++j) if (j != i) cout << ' ' << j;
        cout << endl;
        int pos, ans;
        cin >> pos >> ans;
        ++cnt[ans];
    }
    assert(cnt.size() == 2);
    auto it = cnt.begin(); ++it;
    cout << "! " << (it->second) << endl;
    return 0;
}