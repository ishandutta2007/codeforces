#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int LG = 31;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> bt(LG, -1);
    int pref = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pref ^= x;
        int y = pref;
        while (y != 0) {
            int b = 31 - __builtin_clz(y);
            if (bt[b] == -1) {
                bt[b] = y;
                ans++;
                break;
            }
            y ^= bt[b];
        }
    }
    if (!pref)
        ans = -1;
    cout << ans << '\n';
}