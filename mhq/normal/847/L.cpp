#include <bits/stdc++.h>

using namespace std;
char last;
int st[2000];
int parent[2000];
int o[2000];
set<int> s[1010][1010];
vector<int> lst[1010][1010];
vector<int> ed[1010];
int sz, l;
int dg[3000];
int mar[3000];
int n;
int get_int() {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    int x = 0;
    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    last = c;
    return x;
}
void add(int x, int y) {
    if (mar[y] == 1) {
        cout << "-1\n";
        exit(0);
    }
    if (sz == n - 1) return;
    mar[y] = 1;
    sz++;
    ed[x].push_back(y);
    ed[y].push_back(x);
    o[sz] = y;
    parent[y] = x;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= st[i]; j++) s[i][j].erase(y);
}
void bad() {
    cout << "-1\n";
    exit(0);
}
vector<int> ord;
void dfs(int x, int p) {
    mar[x] = 1;
    ord.push_back(x);
    for (int i = 0; i < ed[x].size(); i++) {
        int to = ed[x][i];
        if (mar[to] == 1 && to != p) bad();
        if (mar[to] == 1) continue;
        dfs(to, x);

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    n = get_int();
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (;;) {
            int x = get_int();
            cnt++;
            while (last != '-' && last != '\n') {
                int y = get_int();
                s[i][cnt].insert(y);
                lst[i][cnt].push_back(y);
            }
            sort(lst[i][cnt].begin(), lst[i][cnt].end());
            if (last == '\n') break;
        }
        sort(lst[i] + 1, lst[i] + cnt + 1);
        st[i] = cnt;
        dg[i] = cnt;
    }
    sz = 0;
    l = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= st[i]; j++) {
            if (s[i][j].size() == 1 && dg[*(s[i][j].begin())] == 1) add(i, *(s[i][j].begin()));
        }
    }
    while (l <= sz) {
        int x = parent[o[l]];
        dg[x]--;
        if (dg[x] == 1) {
            for (int i = 1; i <= n; i++)
            for (int j = 1; j <= st[i]; j++)
                if (s[i][j].find(x) != s[i][j].end() && s[i][j].size() == 1) {
                    add(i, x);
                    break;
                }
        }
        l++;
    }
    if (sz < n - 1) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i] != ed[i].size()) bad();
        for (int j = 1; j <= n; j++) mar[j] = 0;
        vector<vector<int>> ch;
        mar[i] = 1;
        for (int j = 0; j < ed[i].size(); j++) {
            int to = ed[i][j];
            ord.clear();
            dfs(to, i);
            sort(ord.begin(), ord.end());
            ch.push_back(ord);
        }
        sort(ch.begin(), ch.end());
        for (int j = 1; j <= st[i]; j++)
            if (ch[j - 1] != lst[i][j]) bad();
    }
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++)
        if (parent[i] != 0) cout << i << " " << parent[i] << "\n";
    return 0;
}