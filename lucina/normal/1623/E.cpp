#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int l[nax];
int r[nax];
char c[nax];
string s;
int where[nax];
bool dup[nax];
bool smaller[nax];

void dfs(int x) {
    if (!x) return;
    dfs(l[x]);
    where[x] = s.size();
    s += c[x];
    dfs(r[x]);
}

pair <bool, int> try_opt(int x, int res_k) {
    if (!x) return make_pair(false, res_k);
    if (res_k == 0) return make_pair(false, res_k);
    if (smaller[where[x]]) {
        dup[x] = true;
        auto [opt, has] = try_opt(l[x], res_k - 1);
        if (opt) {
            res_k = has;
        } else res_k -= 1;
        tie(opt, has) = try_opt(r[x], res_k);
        if (opt) res_k = has;
        return make_pair(true, res_k);
    } else {
        auto [opt, has] = try_opt(l[x], res_k - 1);
        if (opt) {
            dup[x] = true;
            res_k = has;
            tie(opt, has) = try_opt(r[x], res_k);
            if (opt) res_k = has;
            return make_pair(true, res_k);
        }
        return make_pair(false, res_k);
    }
}

void dfs_ans(int x) {
    if (!x) return;
    dfs_ans(l[x]);
    s += c[x];
    if (dup[x]) s += c[x];
    dfs_ans(r[x]);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k >> c + 1;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> l[i] >> r[i];
    }
    dfs(1);
    for (int i = 0 ; i < s.size() ;) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) ++ j;
        char jj = j < s.size() ? s[j] : 0;
        if (s[i] < jj) {
            for (int k = i ; k < j ; ++ k)
                smaller[k] = true;
        }
        i = j;
    }
    try_opt(1, k);
    s.clear();
    dfs_ans(1);
    cout << s << '\n';
}