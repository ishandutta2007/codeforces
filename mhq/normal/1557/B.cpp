#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        int k, n;
        cin >> n >> k;
        vector<int> a(n);
        for (int& v : a) cin >> v;
        auto b = a;
        sort(b.begin(), b.end());
        int tot = 0;
        int ptr = 0;
        while (ptr < n) {
            tot++;
            int pos = lower_bound(b.begin(), b.end(), a[ptr]) - b.begin();
            int nptr = ptr;
            while (nptr < n && pos + nptr - ptr < n && a[nptr] == b[pos + nptr - ptr]) nptr++; nptr--;
            ptr = nptr + 1;
        }
        if (tot <= k) cout << "YES\n";
        else cout << "NO\n";
    }
}