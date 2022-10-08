
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 24;
int xs, ys, n, x, y;
complex<int> pt[N];
int dp[1 << N];
int match[1 << N];

// (3, 2), (2, 3), (-1, -1)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> xs >> ys >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        pt[i] = {x - xs, y - ys};
    }
    int m = 1 << n;
    for(int mask = 1; mask < m; mask++) {
        dp[mask] = 1e9;
        int i = 0;
        while(((mask >> i) & 1) == 0) i++;
        dp[mask] = 2 * norm(pt[i]) + dp[mask - (1 << i)];
        match[mask] = -1;
        for(int j = i + 1; j < n; j++) {
            if((mask >> j) & 1) {
                int dist = norm(pt[i]) + norm(pt[j]) + norm(pt[i] - pt[j]);
                int cost = dp[mask - (1 << i) - (1 << j)] + dist;
                if(cost < dp[mask]) {
                    dp[mask] = cost;
                    match[mask] = j;
                }
            }
        }
    }
    cout << dp[m - 1] << endl;
    int mask = m - 1;
    cout << 0;
    while(mask) {
        int i = 0;
        while(((mask >> i) & 1) == 0) i++;
        int j = match[mask];
        cout << " " << i+1;
        mask -= (1 << i);
        if(j != -1) {
            cout << " " << j+1;
            mask -= (1 << j);
        }
        cout << " 0";
    }
    cout << endl;
}