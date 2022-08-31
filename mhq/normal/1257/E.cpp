#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int k1, k2, k3;
int clr[maxN];
int bal[maxN];
int cnt_one[maxN];
int cnt_two[maxN];
int cnt_tri[maxN];
int n;
int max_bal[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> k1 >> k2 >> k3;
    for (int i = 1; i <= k1; i++) {
        int x;
        cin >> x;
        clr[x] = 1;
    }
    for (int i = 1; i <= k2; i++) {
        int x;
        cin >> x;
        clr[x] = 2;
    }
    for (int i = 1; i <= k3; i++) {
        int x;
        cin >> x;
        clr[x] = 3;
    }
    n = k1 + k2 + k3;
    for (int i = 1; i <= n; i++) {
        cnt_one[i] = cnt_one[i - 1] + (clr[i] == 1);
        cnt_two[i] = cnt_two[i - 1] + (clr[i] == 2);
        cnt_tri[i] = cnt_tri[i - 1] + (clr[i] == 3);
    }
    int cur_bal = 0;
    for (int i = n; i >= 1; i--) {
        if (clr[i] == 3) cur_bal++;
        else if (clr[i] == 2) cur_bal--;
        max_bal[i] = max(max_bal[i + 1], cur_bal);
    }
    int mx = 0;
    for (int pref = 0; pref <= n; pref++) {
        int val1 = cnt_one[pref];
        int has_two = k2 - cnt_two[pref];
        val1 += has_two + max_bal[pref + 1];
        mx = max(mx, val1);
    }
    cout << n - mx;
    return 0;
}