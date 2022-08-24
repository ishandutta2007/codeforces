#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 10;
int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int n;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int a[maxN];
int inv[maxN];
int fact;
void calc() {
    inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult((mod - (mod / i)), inv[mod % i]);
    }
    fact = 1;
    for (int i = 2; i <= n; i++) fact = mult(fact, i);
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n;
    //n = rand() % 5;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //a[i] = rand() % 10;
    }
    calc();
    sort(a + 1, a + n + 1);
    int mx = a[n];
    int ans = 0;
    int x = 0;
    int prv = 0;
    int sz = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) break;
        if (i > 1) {
            if (a[i] == a[i - 1]) sz++;
            else {
                prv = prv + sz;
                sz = 1;
            }
        }
        ans = sum(ans, mult(mult(a[i], fact), inv[n - prv]));
        //cout << prv << '\n';
    }
    cout << ans << '\n';
    /*int b[500];
    int c[500];
    for (int i = 1; i <= n; i++) b[i] = i;
    //sort(a + 1, a + n + 1);
    int anss = 0;
    for (int i = 1; i <= n; i++) c[i] = a[i];
    do {
        for (int i = 1; i <= n; i++) {
            a[i] = c[b[i]];
        }
        //for (int i = 1; i <= n; i++) cout << a[i] << " ";
        //cout << '\n';
        int f = 0;
        int cur = a[1];
        for (int i = 2; i <= n; i++){
            if (a[i] > cur) {
                f += cur;
                cur = a[i];
            }
        }
        anss += f;
    } while(next_permutation(b + 1, b + n + 1));
    cout << anss;
        /*if (ans != anss) {
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            return 0;
        }*/
    return 0;
}