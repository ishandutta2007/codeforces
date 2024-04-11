#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> vert;
vector<int> hor;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        vert.PB(x);
    }
    vert.PB(1e9);
    for (int i = 0; i < m; ++i) {
        int y, x1, x2;
        scanf("%d%d%d", &x1, &x2, &y);
        if (x1 == 1) {
            hor.PB(x2);
        }
    }
    sort(hor.begin(), hor.end());
    sort(vert.begin(), vert.end());
    int ans = inf;
    for (int i = 0; i < vert.size(); ++i) {
        int cur_ans = i;
        auto it = lower_bound(hor.begin(), hor.end(), vert[i]);
        cur_ans += (hor.end() - it);
        ans = min(ans, cur_ans);
    }
    cout << ans;

    return 0;
}