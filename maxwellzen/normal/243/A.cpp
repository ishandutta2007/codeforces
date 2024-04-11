#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i++) cin >> a[i];
    int x[20];
    for (int i = 0; i < 20; i++) x[i] = 0;
    set<int> ans;
    for (int L = n-1; L >= 0; L--) {
        ans.insert(a[L]);
        for (int bit = 0; bit < 20; bit++) {
            if (a[L] & 1<<bit) x[bit] = 0;
            x[bit] |= a[L];
            ans.insert(x[bit]);
        }
    }
    cout << ans.size() << endl;
}