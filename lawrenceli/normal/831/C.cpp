#include <bits/stdc++.h>
using namespace std;

int k, n, a[2005], c[2005];
set<int> b;

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int x; cin >> x; b.insert(x);
    }
    
    set<int> ans;
    int x = *b.begin();
    for (int i = 0; i < k; i++) {
        c[i] = x;
        for (int j = i + 1; j < k; j++) c[j] = c[j - 1] + a[j];
        for (int j = i - 1; j >= 0; j--) c[j] = c[j + 1] - a[j + 1];
        bool good = true;
        set<int> st (c, c + k);
        for (int y : b)
            if (!st.count(y)) {
                good = false;
                break;
            }
        if (good) ans.insert(c[0] - a[0]);
    }
    
    cout << ans.size() << endl;
}