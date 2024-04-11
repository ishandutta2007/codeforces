#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, k;
int x[maxn];

vector<int> idxs[maxn];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x[i]);
        idxs[x[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (idxs[i].empty()) {
            ans += int(i > 1) + int(i < n) + 1;
        } else {
            int j = idxs[i][0];
            if (i > 1 && lower_bound(idxs[i-1].begin(), idxs[i-1].end(), j) == idxs[i-1].end()) {
                ans++;
            }
            if (i < n && lower_bound(idxs[i+1].begin(), idxs[i+1].end(), j) == idxs[i+1].end()) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
}