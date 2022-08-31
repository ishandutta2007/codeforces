#include <bits/stdc++.h>

using namespace std;
int x;
const int maxN = (int)1e6 + 10;
int lp[maxN];
vector < int > pr;
int f[maxN];
void calc() {
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && 1LL * pr[j] * i < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
    for (int i = 2; i < maxN; i++) {
        int t = i;
        int p = lp[i];
        while (t > 1) {
            p = max(lp[t], p);
            t /= lp[t];
        }
        if (i == lp[i]) f[i] = (int)1e9;
        else f[i] = i - p + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    calc();
    cin >> x;
    int mn = (int)1e9;
    int mx = -1;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0 && lp[i] == i) {
            mx = max(mx, i);
        }
    }
    for (int j = x - mx + 1; j <= x; j++) mn = min(mn, f[j]);
    cout << mn;
    return 0;
}