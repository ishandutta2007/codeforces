#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
const int maxN = 105;
int h[maxN];
int pos[maxN];
int a[maxN];
int tp = 0;
bool cmp(int a, int b) {
    return pos[a] < pos[b];
}
bool dp[maxN];
int prv[maxN];
int max_val[maxN];
void solve1(int where) {
    vector < int > left, right;
    for (int i = 1; i <= m; i++) {
        if (pos[i] < where) left.push_back(i);
        else right.push_back(i);
    }
    sort(left.begin(), left.end(), cmp);
    reverse(left.begin(), left.end());
    sort(right.begin(), right.end(), cmp);
    for (int i = 0; i < left.size(); i++) {
        int v = left[i];
        int cur_hp = 0;
        int cur_pos = pos[v];
        int mx_pos = cur_pos;
        for (int start = cur_pos; start <= where + 1; start++) {
            cur_hp += a[start];
            if (cur_hp + h[v] < 0 || start == where + 1) {
                mx_pos = start - 1;
                break;
            }
        }
        dp[i] = false;
        if (mx_pos == where) {
            dp[i] = true;
            prv[i] = -1;
        }
        else {
            for (int j = 0; j < i; j++) {
                if (dp[j] && pos[left[j]] <= mx_pos) {
                    dp[i] = true;
                    prv[i] = j;
                    break;
                }
            }
        }
    }
    vector < int > ans_left;
    if (!left.empty()) {
        vector < bool > used(left.size(), false);
        if (!dp[left.size() - 1]) return ;
        int cur = left.size() - 1;
        while (cur != -1) {
            used[cur] = true;
            ans_left.push_back(left[cur]);
            cur = prv[cur];
        }
        reverse(ans_left.begin(), ans_left.end());
        for (int i = 0; i < left.size(); i++) {
            if (!used[i]) {
                ans_left.push_back(left[i]);
            }
        }
    }
    for (int i = 0; i < right.size(); i++) {
        int v = right[i];
        int cur_hp = 0;
        int cur_pos = pos[v];
        int mx_pos = cur_pos;
        for (int start = cur_pos; start >= where - 1; start--) {
            cur_hp += a[start];
            if (cur_hp + h[v] < 0 || start == where - 1) {
                mx_pos = start + 1;
                break;
            }
        }
        dp[i] = false;
        if (mx_pos == where || (!left.empty() && mx_pos == where + 1)) {
            dp[i] = true;
            prv[i] = -1;
        }
        else {
            for (int j = 0; j < i; j++) {
                if (dp[j] && pos[right[j]] >= mx_pos) {
                    dp[i] = true;
                    prv[i] = j;
                    break;
                }
            }
        }
    }
    vector < int > ans_right;
    if (!right.empty()) {
        vector < bool > used(right.size(), false);
        if (!dp[right.size() - 1]) return ;
        int cur = right.size() - 1;
        while (cur != -1) {
            used[cur] = true;
            ans_right.push_back(right[cur]);
            cur = prv[cur];
        }
        reverse(ans_right.begin(), ans_right.end());
        for (int i = 0; i < right.size(); i++) {
            if (!used[i]) {
                ans_right.push_back(right[i]);
            }
        }
    }
    cout << where << '\n';
    for (int v : ans_left) cout << v << " ";
    for (int v : ans_right) cout << v << " ";
    exit(0);
}
void solve2(int where) {
    vector < int > left, right;
    for (int i = 1; i <= m; i++) {
        if (pos[i] < where) left.push_back(i);
        else right.push_back(i);
    }
    sort(left.begin(), left.end(), cmp);
    reverse(left.begin(), left.end());
    sort(right.begin(), right.end(), cmp);
    for (int i = 0; i < left.size(); i++) {
        int v = left[i];
        int cur_hp = 0;
        int cur_pos = pos[v];
        int mx_pos = cur_pos;
        for (int start = cur_pos; start <= where + 1; start++) {
            cur_hp += a[start];
            if (cur_hp + h[v] < 0 || start == where + 1) {
                mx_pos = start - 1;
                break;
            }
        }
        dp[i] = false;
        if ((mx_pos == where) || (mx_pos == where - 1 && !right.empty())) {
            dp[i] = true;
            prv[i] = -1;
        }
        else {
            for (int j = 0; j < i; j++) {
                if (dp[j] && pos[left[j]] <= mx_pos) {
                    dp[i] = true;
                    prv[i] = j;
                    break;
                }
            }
        }
    }
    vector < int > ans_left;
    if (!left.empty()) {
        vector < bool > used(left.size(), false);
        if (!dp[left.size() - 1]) return ;
        int cur = left.size() - 1;
        while (cur != -1) {
            used[cur] = true;
            ans_left.push_back(left[cur]);
            cur = prv[cur];
        }
        reverse(ans_left.begin(), ans_left.end());
        for (int i = 0; i < left.size(); i++) {
            if (!used[i]) {
                ans_left.push_back(left[i]);
            }
        }
    }
    for (int i = 0; i < right.size(); i++) {
        int v = right[i];
        int cur_hp = 0;
        int cur_pos = pos[v];
        int mx_pos = cur_pos;
        for (int start = cur_pos; start >= where - 1; start--) {
            cur_hp += a[start];
            if (cur_hp + h[v] < 0 || start == where - 1) {
                mx_pos = start + 1;
                break;
            }
        }
        dp[i] = false;
        if (mx_pos == where) {
            dp[i] = true;
            prv[i] = -1;
        }
        else {
            for (int j = 0; j < i; j++) {
                if (dp[j] && pos[right[j]] >= mx_pos) {
                    dp[i] = true;
                    prv[i] = j;
                    break;
                }
            }
        }
    }
    vector < int > ans_right;
    if (!right.empty()) {
        vector < bool > used(right.size(), false);
        if (!dp[right.size() - 1]) return ;
        int cur = right.size() - 1;
        while (cur != -1) {
            used[cur] = true;
            ans_right.push_back(right[cur]);
            cur = prv[cur];
        }
        reverse(ans_right.begin(), ans_right.end());
        for (int i = 0; i < right.size(); i++) {
            if (!used[i]) {
                ans_right.push_back(right[i]);
            }
        }
    }
    cout << where << '\n';
    for (int v : ans_right) cout << v << " ";
    for (int v : ans_left) cout << v << " ";
    exit(0);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> pos[i] >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int where = 1; where <= n; where++) {
        solve1(where);
        solve2(where);
    }
    cout << -1;
    return 0;
}