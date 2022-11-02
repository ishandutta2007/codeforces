#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int maxn = 5005;

int n;
int t[maxn], freq[maxn], ans[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) {
        memset(freq, 0, sizeof(freq));
        pii best = pii(1e9, 1e9);
        for (int j = i; j < n; j++) {
            int v = t[j];
            freq[v]--;
            pii p = pii(freq[v], v);
            if (p < best) best = p;
            ans[best.second]++;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}