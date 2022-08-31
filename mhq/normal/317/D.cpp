#include <bits/stdc++.h>
using namespace std;
map < int, int > q;
int ans[35];
int c[35];
int mex(vector < int > &p) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < p.size(); i++) c[p[i]]++;
    int i = 1;
    while (c[i]) i++;
    return i;
}
int solve(int mask) {
    if (mask == 0) return 1;
    if (q[mask] != 0) return q[mask];
    //memset(c, 0, sizeof c);
    vector < int > p;
    for (int j = 1; j <= 30; j++) {
        if ((mask & (1 << (j - 1))) == 0) continue;
        int nmask = mask;
        for (int k = j - 1; k <= 29; k += j) {
            if (nmask & (1 << k)) nmask ^= (1 << k);
        }
        p.push_back(solve(nmask));
    }
    q[mask] = mex(p);
    return q[mask];
}
int n;
bool used[(int)1e5 + 10];
int r_ans[30] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
int main() {
    //freopen("input.txt", "w", stdout);
    //cout << solve(3) << " " << solve(5) << " " << solve(0) << endl;
    //cout << solve(7) << endl;
    cin >> n;
    int get = 0;
    int left = 0;
    for (int i = 1; i * i <= n; i++) {
        if (used[i]) continue;
        //cout << i << endl;
        long long st = i;
        int cur = 0;
        if (i == 1) {
            get ^= 1;
            continue;
        }
        for (st = i; st <= n; st *= i) {
            cur++;
            if (st * st > n) left--;
            else used[st] = true;
        }
        //cout << cur << endl;
        get ^= r_ans[cur];
    }
    int p = sqrt(n) + 3;
    while ((p - 1) * (p - 1) > n) p--;
    p -= left;
    //cout << n - p + 1 << endl;
    if ((n - p + 1) & 1) get ^= 1;
    if (get) cout << "Vasya";
    else cout << "Petya";
    /*for (int i = 0; i <= 29; i++) {
        int mask = 0;
        for (int j = 0; j < i; j++) mask |= (1 << j);
        //cout << mask << endl;
        ans[i] = solve(mask) - 1;
    }
    cout << solve(3) << " " << solve(5) << " " << solve(7) << endl;
    for (int i = 0; i <= 29; i++) cout << ans[i] << ", ";*/
}