#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, p;
int L[N], R[N];
int cntP[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin >> n >> p;

    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        cntP[i] = R[i] / p - (L[i] - 1) / p;
    }

    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        int nxt = i % n + 1;
        ans += (long double)((long long)cntP[nxt] * (R[i] - L[i] + 1) + (long long)cntP[i] * (R[nxt] - L[nxt] + 1) - (long long)cntP[i] * cntP[nxt]) / (long double)(R[i] - L[i] + 1) / (long double)(R[nxt] - L[nxt] + 1);
    }

    cout << fixed << setprecision(15) << 2000L * ans << endl;

    return 0;
}