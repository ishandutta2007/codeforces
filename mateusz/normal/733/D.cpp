#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
int size[3];
unordered_map<long long, pair<int, int> > m;

int main() {

    scanf("%d", &n);
    int best = -1;
    pair<int, int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &size[j]);
        }
        sort(size, size + 3);
        if (size[0] > best) {
            best = size[0];
            ans = {i, -1};
        }
        int j = 1;
        int k = 2;
        long long hash = (long long)size[j] * (1e9 + 1) + size[k];
        int remaining = 0;
        if (m.count(hash)) {
            pair<int, int> who = m[hash];
            int longest = min(size[j], size[remaining] + who.first);
            if (longest > best) {
                best = longest;
                ans = {who.second, i};
            }
            m[hash] = max(m[hash], {size[remaining], i});
        } else {
            m[hash] = {size[remaining], i};
        }
    }

    if (ans.second == -1) {
        printf("1\n%d\n", ans.first);
    } else {
        printf("2\n%d %d\n", ans.first, ans.second);
    }

    return 0;
}