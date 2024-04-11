#include <bits/stdc++.h>

using namespace std;

const int maxN = 10000;

int a[maxN], n, k, m, aa, ans[maxN], la[maxN];

int get(int ind) {
    if (a[ind] == 0) return false;
    vector<int> pool;
    for (int i = 1; i <= n; ++i) {
        if (i == ind) continue;
        if (a[i] > a[ind]) {
            pool.push_back(0);
        } else {
            if (a[i] < a[ind]) {
                pool.push_back(a[ind] - a[i] + 1);
            } else {
                if (la[i] < la[ind]) pool.push_back(0); else pool.push_back(1);
            }
        }
    }
    sort(pool.begin(), pool.end());
    int cnt = 0;
    int tmp = m - aa;
    for (int i = 0; i < pool.size(); ++i) {
        if (pool[i] <= tmp) {
            tmp -= pool[i];
            ++cnt;
        }
    }
    return cnt;
}

int cur_la;

int go(int ind) {
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == ind) continue;
        if (a[i] > a[ind]) cur++; else
        if (a[i] == a[ind] && la[i] < cur_la && a[i] > 0) ++cur;
    }
    return cur;
}

bool bad(int ind) {
    int tmp_add = m - aa;
    a[ind] += tmp_add;
    cur_la = la[ind];
    if (tmp_add > 0) cur_la = m;
    int cur = go(ind);
    a[ind] -= tmp_add;
    if (a[ind] + tmp_add == 0) {
        return true;
    }
    if (cur < k) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> m >> aa;
    for (int i = 1; i <= aa; ++i) {
        int ind;
        cin >> ind;
        ++a[ind];
        la[ind] = i;
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = 2;
    }
    for (int i = 1; i <= n; ++i) {
        int cur = get(i);
        if (cur < k && a[i] > 0) ans[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (bad(i)) {
            ans[i] = 3;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}