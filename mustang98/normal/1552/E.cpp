#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 103, inf = 1000111222;

int m[max_n * max_n];
int cnt[max_n * max_n];
int n, k;
int mx;
int lst[max_n];
bool used[max_n];
pair<int, int> res[max_n];

int get_max(int from, int to) {
    int ans = cnt[from];
    for (int i = from + 1; i <= to; ++i) {
        ans = cnt[i] > ans ? cnt[i] : ans;
    }
    return ans;
}

void add1(int from, int to) {
    for (int i = from; i <= to; ++i) {
        ++cnt[i];
    }
}

vector<pair<int, int>> solve() {
    vector<pair<int, int>> ans;
    memset(used, 0, sizeof(used));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i <= n; ++i) {
        lst[i] = -1;
        res[i] = MP(-1, -1);
    }
    for (int i = 0; i < n * k; ++i) {
        int cur = m[i];
        //cout << "%% " << cur << endl;
        if (used[cur]) {
            continue;
        }
        int pr = lst[cur];
        lst[cur] = i;
        if (pr == -1) {
            continue;
        }
        int tp = get_max(pr, i);
        //cout << "$$ " << cur << ' ' << pr << ' ' << i << ' ' << tp << endl;
        if (tp == mx) {
            continue;
        }
        //cout << "ADD" << endl;
        used[cur] = true;
        res[cur] = MP(pr, i);
        add1(pr, i);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            return ans;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans.PB(res[i]);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n * k; ++i) {
        cin >> m[i];
        --m[i];
    }
    mx = (n + k - 2) / (k - 1);
    //cout << "$$ " << mx << endl;
    vector<pair<int, int>> ans = solve();
    if (ans.empty()) {
        reverse(m, m + n * k);
        ans = solve();
        if (ans.empty()) {
            exit(228);
        }
        for (int i = 0; i < n; ++i) {
            ans[i].F = (n * k - 1 - ans[i].F);
            ans[i].S = (n * k - 1 - ans[i].S);
            swap(ans[i].F, ans[i].S);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].F + 1 << ' '  << ans[i].S + 1 << "\n";
    }
    return 0;
}