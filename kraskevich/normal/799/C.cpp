#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1000 * 1000;

int max_b[N][2];
int pre[N][2];
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> coins{c, d};
    int res = 0;
    for (int i = 0; i < n; i++) {
        int b, p;
        cin >> b >> p;
        char t;
        cin >> t;
        int idx = 0;
        if (t == 'D')
            idx = 1;
        if (max_b[p][idx] && 2 * p <= coins[idx])
            res = max(res, max_b[p][idx] + b);
        max_b[p][idx] = max(max_b[p][idx], b);
    }
    for (int i = 1; i < N; i++)
        for (int j = 0; j < 2; j++)
            pre[i][j] = max(max_b[i][j], pre[i - 1][j]);
    if (pre[coins[0]][0] && pre[coins[1]][1])
        res = max(res, pre[coins[0]][0] + pre[coins[1]][1]);
    for (int i = 1; i < N; i++)
        for (int j = 0; j < 2; j++) {
            int small = min(i - 1, coins[j] - i);
            if (small <= 0)
                continue;
            if (pre[small][j] && max_b[i][j])
                res = max(res, pre[small][j] + max_b[i][j]);
        }
    cout << res << endl;
}