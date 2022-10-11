#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, te, a[2 * N];
bitset<N> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        ans.reset();
        ans.set(0);
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
        }
        a[2 * n + 1] = 2 * N + 1;
        for (int i = 1; i <= 2 * n; i++) {
            int he = a[i], sz = 1;
            while (a[i + 1] < he) {
                i++;
                sz++;
            }
            ans |= (ans << sz);
        }
        cout << (ans.test(n) ? "YES\n" : "NO\n");
    }
}