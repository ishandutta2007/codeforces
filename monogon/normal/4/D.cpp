
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5005;
int n, w, h, a[N], b[N];
set<int> sx, sy;
vector<int> vx, vy;
uint16_t dp[N][N];
vector<tuple<int, int, int>> cards;

bool iscard(int i, int j) {
    auto it = lower_bound(cards.begin(), cards.end(), make_tuple(vx[i], vy[j], 0));
    return it != cards.end() && get<0>(*it) == vx[i] && get<1>(*it) == vy[j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> h;
    sx.insert(w + 1);
    sy.insert(h + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sx.insert(a[i]);
        sy.insert(b[i]);
        cards.emplace_back(a[i], b[i], i);
    }
    sort(cards.begin(), cards.end());
    vx = vector<int>(sx.begin(), sx.end());
    vy = vector<int>(sy.begin(), sy.end());
    int i = (int) vx.size() - 1;
    int j = (int) vy.size() - 1;
    for(; i >= 0 && vx[i] >= w + 1; i--) {
        for(j = (int) vy.size() - 1; j >= 0 && vy[j] >= h + 1; j--) {
            dp[i][j] = max((int) iscard(i, j) + dp[i + 1][j + 1], max((int) dp[i + 1][j], (int) dp[i][j + 1]));
        }
    }
    i++; j++;
    int cnt = 0;
    int i2 = i, j2 = j;
    cout << dp[i][j] << endl;
    while(i2 < (int) vx.size() && j2 < (int) vy.size() && cnt < dp[i][j]) {
        if(iscard(i2, j2) && dp[i2][j2] == 1 + dp[i2 + 1][j2 + 1]) {
            cnt++;
            auto it = lower_bound(cards.begin(), cards.end(), make_tuple(vx[i2], vy[j2], 0));
            int idx = get<2>(*it);
            cout << (idx + 1) << " ";
            i2++;
            j2++;
        }else if(dp[i2][j2] == dp[i2 + 1][j2]) {
            i2++;
        }else j2++;
    }
    cout << endl;
}