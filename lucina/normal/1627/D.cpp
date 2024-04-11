#include<bits/stdc++.h>
using namespace std;
const int L = 1e6;
const int nax = 1e6 + 10;
int n;
int a[nax];
bool has[L];
int g[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        has[a[i]] = true;
    }
    for (int i = 1 ; i <= L ; ++ i) {
        for (int j = i ; j <= L ; j += i) {
            if (!has[j]) continue;
            g[i] = gcd(g[i], j);
        }
    }
    for (int i = 1 ; i <= L ; ++ i)
        if (g[i] == i) has[i] = true;
    int ans = count(has + 1, has + 1 + L, true);
    cout << ans - n << '\n';
}
/*
    Hm, don't know what to write?
    Well, just have fun I suppose.
*/