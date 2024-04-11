#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int h[11];
int mi[11];
int cop[11];
bool used[11];
vector < int > t;
int need (int i) {
    int q1 = max(max((h[i] + a - 1) / a, (h[i - 1] + b - 1) / b), (h[i + 1] + b - 1) / b);
    h[i - 1] -= q1 * b;
    h[i + 1] -= q1 * b;
    h[i] -= q1 * a;
    return q1;
}
int ch(int q) {
    int an = 0;
    for (int i = 0; i < t.size(); i++) {
        mi[t[i]] = q % 17;
        q = q / 17;
        h[t[i]] -= mi[t[i]] * a;
        h[t[i] - 1] -= mi[t[i]] * b;
        h[t[i] + 1] -= mi[t[i]] * b;
        an += mi[t[i]];
    }
    for (int i = 1; i <= n; i++) {
        if (h[i] < 0) h[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            an += need(i);
        }
    }
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (h[i] > 0) ok = true;
    }
    for (int i = 1; i <= n; i++) h[i] = cop[i];
    if (ok) return -1;
    return an;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        h[i]++;
        cop[i] = h[i];
    }
    for (int i = 2; i < n; i += 3) used[i] = true;
    for (int i = 2; i < n; i++) {
        if (!used[i]) t.push_back(i);
    }
    int p = 1;
    for (int i = 0; i < t.size(); i++) {
        p = p * 17;
    }
    int q = 0;
    int ans = 10000;
    int cur;
    while (q < p) {
        if (ch(q) != -1) {
            if (ans > ch(q)) {
                ans = ch(q);
                cur = q;
            }
        }
        q++;
    }
    vector < int > an;
    for (int i = 0; i < t.size(); i++) {
        mi[t[i]] = cur % 17;
        cur = cur / 17;
        h[t[i]] -= mi[t[i]] * a;
        h[t[i] - 1] -= mi[t[i]] * b;
        h[t[i] + 1] -= mi[t[i]] * b;
        for (int k = 0; k < mi[t[i]]; k++) an.push_back(t[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (h[i] < 0) h[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            int z1 = need(i);
            for (int k = 0; k < z1; k++) an.push_back(i);
        }
    }
    cout << an.size() << "\n";
    for (int i = 0; i < an.size(); i++) cout << an[i] << " ";
    return 0;
}