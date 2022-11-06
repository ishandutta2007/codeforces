#include <bits/stdc++.h>

using namespace std;

const int N = 22, INF = 1e9;

int dp[1 << N];
int parent[1 << N], parentState[1 << N];
int n, m, a, b;
int edges[N + 2];

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a] |= (1 << b);
        edges[b] |= (1 << a);
    }
    bool all = true;
    for (int j = 0; j < n; j++) {
        if ((edges[j] | (1 << j)) != (1 << n) - 1) {
            all = false;
            break;
        }
    }
    if (all) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i < (1 << n); i++) {
        dp[i] = INF;
    }
    
    for (int i = 1; i < (1 << n); i++) {
        if ((i & (i - 1)) == 0) {
//             cerr << i << endl;
            dp[i] = 0;
//             parent[i] = __builtin_ctz(i);
        }
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                if (dp[i | edges[j]] > dp[i] + 1) {
                    dp[i | edges[j]] = dp[i] + 1;
                    parent[i | edges[j]] = j;
                    parentState[i | edges[j]] = i;
                }
            }
        }
    }
    
    printf("%d\n", dp[(1 << n) - 1]);
    vector<int> guys;
    int w = (1 << n) - 1;
    while ((w & (w - 1)) > 0) {
        guys.push_back(parent[w]);
        w = parentState[w];
//         cerr << w << " " << parent[w] << endl;
    }
    reverse(guys.begin(), guys.end());
    for (int x : guys) {
        printf("%d ", x + 1);
    }
    return 0;
}