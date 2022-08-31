#include <bits/stdc++.h>

using namespace std;
const int maxN = 2005;
const int mod  = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int c[maxN][maxN], fact[maxN];
bool a[maxN], b[maxN];
int n;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mult(fact[i - 1], i);
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = true;
        b[i] = true;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != -1) {
            a[i] = false;
            b[x] = false;
        }
    }
    int fi = 0;
    int ot = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] && b[i]) fi++;
        else if (a[i]) ot++;
    }
    int ans = 0;
    for (int i = 0; i <= fi; i++) {
        if (!(i & 1)) ans = sum(ans, mult(c[fi][i], fact[ot + fi - i]));
        else ans = sub(ans, mult(c[fi][i], fact[ot + fi - i]));
    }
    cout << ans;
	return 0;
}