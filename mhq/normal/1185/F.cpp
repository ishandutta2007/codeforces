#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxK = (1 << 9) + 10;
pair < int, int > best[maxK][2];
int cnt[maxK];
int n, m;
const int INF = (int)1e9 + 100;
pair < int, int > ans;
int ind1 = -1;
int ind2 = -1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < maxK; i++) {
        for (int j = 0; j < 2; j++) {
            best[i][j] = make_pair(INF, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        int f;
        cin >> f;
        int msk = 0;
        for (int j = 0; j < f; j++) {
            int b;
            cin >> b;
            b--;
            msk |= (1 << b);
        }
        cnt[msk]++;
    }
    for (int i = 1; i <= m; i++) {
        int cost;
        cin >> cost;
        int f;
        cin >> f;
        int msk = 0;
        for (int j = 0; j < f; j++) {
            int b;
            cin >> b;
            b--;
            msk |= (1 << b);
        }
        pair < int, int > t = make_pair(cost, i);
        if (best[msk][0] > t) {
            best[msk][1] = best[msk][0];
            best[msk][0] = t;
        }
        else if (best[msk][1] > t) {
            best[msk][1] = t;
        }
    }
    for (int bit = 0; bit < 9; bit++) {
        for (int msk = 0; msk < (1 << 9); msk++) {
            if (msk & (1 << bit)) {
                cnt[msk] += cnt[msk ^ (1 << bit)];
            }
        }
    }
    ans = make_pair(-1, INF);
    for (int msk1 = 0; msk1 < (1 << 9); msk1++) {
        for (int msk2 = msk1; msk2 < (1 << 9); msk2++) {
            int cost = 0;
            int ind1 = -1;
            int ind2 = -1;
            if (msk1 == msk2) {
                if (best[msk1][1].second == -1) continue;
                ind1 = best[msk1][0].second;
                ind2 = best[msk1][1].second;
                cost = best[msk1][0].first + best[msk2][1].first;
            }
            else {
                if (best[msk1][0].second == -1) continue;
                if (best[msk2][0].second == -1) continue;
                ind1 = best[msk1][0].second;
                ind2 = best[msk2][0].second;
                cost = best[msk1][0].first + best[msk2][0].first;
            }
            int val = cnt[msk1 | msk2];
            if (make_pair(val, -cost) > ans) {
                ans = make_pair(val, -cost);
                ::ind1 = ind1;
                ::ind2 = ind2;
            }
        }
    }
    cout << ind1 << " " << ind2;
    return 0;
}