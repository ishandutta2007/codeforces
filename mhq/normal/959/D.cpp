#include <bits/stdc++.h>
using namespace std;
const int maxN = 5 * (int)1e6 + 10;
int n;
int a[maxN];
bool used[maxN];
int lp[maxN];
vector < int > pr;
void calc() {
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
}
int b[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    calc();
    //cout << "HERE" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool ok = false;
    int prv = 2;
    for (int i = 1; i <= n; i++) {
        //cout << a[i] << endl;
        if (!ok) {
            if (used[a[i]]) {
                ok = true;
                while (used[a[i]]) a[i]++;
            }
        }
        else {
            while (used[prv]) prv++;
            a[i] = prv;
        }
        b[i] = a[i];
        while (a[i] > 1) {
            int p = lp[a[i]];
            a[i] /= p;
            if (used[p]) continue;
            for (int j = p; j < maxN; j += p) used[j] = true;
        }
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    return 0;
}