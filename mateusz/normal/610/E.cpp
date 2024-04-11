#include <bits/stdc++.h>

using namespace std;

const int N = 200005, BASE = 2 * 131072;

int n, m, k, a, b;
char c[N];
int tree[2 * BASE + 5];
char s[N];
set<pair<int, pair<int, int> > >S;
char req[15];
int inc[15][15];
int type;
int cur;

void add(int posa, int posb, int w) {
    if (posa > posb) return;
    posa += BASE;
    posb += BASE;
    tree[posa] = tree[posb] = w;

    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            tree[posa + 1] = max(tree[posa + 1], w);
        }
        if (posb % 2 == 1) {
            tree[posb - 1] = max(tree[posb - 1], w);
        }
        posa /= 2;
        posb /= 2;
    }
}

int query(int pos) {
    pos += BASE;
    int ret = tree[pos];
    while (pos >= 1) {
        ret = max(ret, tree[pos]);
        pos /= 2;
    }
    return ret;
}

void insert(int a, int b, int ch) {
    int cnt = 0;
    set<pair<int, pair<int, int> > >::iterator it = S.lower_bound({a, {0, 0}});
    while (it != S.end() && it->first < b) {
        cnt++;
        inc[it->second.first][it->second.second]--;
        auto it2 = it;
        it2++;
        S.erase(it);
        it = it2;
    }
    if (a - 1 >= 1) {
        it = S.lower_bound({a - 1, {0, 0}});
        if (it != S.end() && it->first == a - 1) {
            inc[it->second.first][it->second.second]--;
            int what = it->second.first;
            S.erase(it);
            inc[what][ch]++;
            S.insert({a - 1, {what, ch}});
        } else {
            cur--;
            int what = c[query(a - 1)] - 96;
            inc[what][ch]++;
            S.insert({a - 1, {what, ch}});
        }
    }
    if (b + 1 <= n) {
        it = S.lower_bound({b, {0, 0}});
        if (it != S.end() && it->first == b) {
            inc[it->second.first][it->second.second]--;
            int what = it->second.second;
            S.erase(it);
            inc[ch][what]++;
            S.insert({b, {ch, what}});
        } else {
            cur--;
            int what = c[query(b)] - 96;
            inc[ch][what]++;
            S.insert({b, {ch, what}});
        }
    }
    cur += cnt;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    scanf("%s", &s[1]);
    for (int i = 1; i <= n; i++) {
        s[i] -= 96;
    }
    for (int i = 1; i < n; i++) {
        inc[s[i]][s[i + 1]]++;
        S.insert({i, {s[i], s[i + 1]}});
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %c", &a, &b, &c[i]);
            insert(a, b, c[i] - 96);
            add(a, b - 1, i);
        } else {
            int ans = 1;
            scanf(" %s", &req[1]);
            for (int j = 1; j <= k; j++) {
                for (int l = j; l <= k; l++) {
                    ans += inc[req[l] - 96][req[j] - 96];
                }
            }
            printf("%d\n", ans + cur);
        }
    }

    return 0;
}