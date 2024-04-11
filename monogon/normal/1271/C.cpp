
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
ll x, y, sx, sy;
int cnt[3][3];

int cmp(ll a, ll b) {
    return a < b ? 0 : a == b ? 1 : 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> sx >> sy;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        cnt[cmp(x, sx)][cmp(y, sy)]++;
    }
    int val1 = cnt[0][0] + cnt[0][1] + cnt[0][2];
    int val2 = cnt[0][0] + cnt[1][0] + cnt[2][0];
    int val3 = cnt[2][0] + cnt[2][1] + cnt[2][2];
    int val4 = cnt[0][2] + cnt[1][2] + cnt[2][2];
    int m = max(max(val1, val2), max(val3, val4));
    if(m == val1) {
        sx--;
    }else if(m == val2) {
        sy--;
    }else if(m == val3) {
        sx++;
    }else if(m == val4) {
        sy++;
    }
    cout << m << endl << sx << " " << sy << endl;
}