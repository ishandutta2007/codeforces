#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 4 * (int)1e6;
int lp[N];
vector < int > pr;
void calc() {
    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= N; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
}
bool check(int a) {
    vector < int > x;
    while (a > 0) {
        x.push_back(a % 10);
        a = a / 10;
    }
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != x[x.size() - 1 - i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    calc();
    int p, q;
    cin >> p >> q;
    int curmax = 0;
    int ind = 0;
    int pri = 0; int pal = 0;
    for (int i = 1; i <= N; i++) {
        while (i > pr[ind] && (ind < pr.size())) ind++;
        if (i == pr[ind]) pri++;
        if (check(i)) pal++;
        if (1LL * q * pri <= 1LL * p * pal) curmax = i;
    }
    cout << curmax;
    return 0;
}