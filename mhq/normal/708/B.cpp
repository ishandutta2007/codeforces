#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef  long double ld;
void solve(int zero, int one, int b, int c) {
    if (zero == 0 && one == 0) return ;
    if (zero == 0 && (b + c > 0)) return ;
    if (one == 0 &&  (b + c > 0)) return ;
    if (b + c != zero * one) return ;
    if (zero == 0) {
        for (int i = 0; i < one; i++) cout << "1";
        exit(0);
    }
    if (one == 0) {
        for (int i = 0; i < zero; i++) cout << "0";
        exit(0);
    }
    vector < int > poses(zero + 1, 0);
    while (b >= zero) {
        b -= zero;
        poses[zero]++;
        one--;
    }
    poses[b]++;
    one--;
    poses[0] += one;
    for (int i = 0; i < poses[0]; i++) cout << "1";
    for (int i = 1; i <= zero; i++) {
        cout << "0";
        for (int j = 0; j < poses[i]; j++) cout << "1";
    }
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector < int > zero, one;
    for (int i = 0; ; i++) {
        if ((1LL * i * (i - 1)) / 2 > a) break;
        if (1LL * i * (i - 1) == 2 * a) zero.push_back(i);
    }
    for (int i = 0; ; i++) {
        if (1LL * i * (i - 1) > 2 * d) break;
        if (1LL * i * (i - 1) == 2 * d) one.push_back(i);
    }
    for (auto t : zero) {
        for (auto v : one) {
            solve(t, v, b, c);
        }
    }
    cout << "Impossible";
    return 0;
}