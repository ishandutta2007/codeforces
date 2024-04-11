#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9 + 7;

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

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = (int)1e5 + 100;
int c[maxN], t[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    vector < int > dif1, dif2;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    if (c[1] != t[1]) {
        cout << "No";
        return 0;
    }
    for (int i = 1; i + 1 <= n; i++) {
        dif1.push_back(c[i + 1] - c[i]);
        dif2.push_back(t[i + 1] - t[i]);
    }
    sort(dif1.begin(), dif1.end());
    sort(dif2.begin(), dif2.end());
    for (int i = 0; i < dif1.size(); i++) {
        if (dif2[i] != dif1[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}