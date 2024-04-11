#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;
vector<int> graph[N], top_sort;
bool used[N];

void dfs_topsort(int v) {
    used[v] = true;
    for (auto u : graph[v])
        if (!used[u])
            dfs_topsort(u);
    top_sort.push_back(v);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> templates;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cur = 0;
        for (int j = 0; j < k; j++)
            cur = cur * 27 + (s[j] == '_' ? 26 : s[j] - 'a');
        templates[cur] = i;
    }

    vector<string> s(m);
    vector<int> which(m);
    vector<vector<int>> good_for_s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> which[i], which[i]--;
        for (int mask = 0; mask < (1 << k); mask++) {
            int cur = 0;
            for (int j = 0; j < k; j++) {
                cur *= 27;
                if ((mask >> j) % 2)
                    cur += s[i][j] - 'a';
                else
                    cur += 26;
            }

            if (templates.find(cur) != templates.end())
                good_for_s[i].push_back(templates[cur]);
        }

        if (find(good_for_s[i].begin(), good_for_s[i].end(), which[i]) == good_for_s[i].end())
            return cout << "NO\n", 0;
        for (auto v : good_for_s[i])
            if (v != which[i])
                graph[which[i]].push_back(v);
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs_topsort(i);
    reverse(top_sort.begin(), top_sort.end());

    vector<int> where(n);
    for (int i = 0; i < n; i++)
        where[top_sort[i]] = i;
    for (int i = 0; i < m; i++) {
        int mn = n;
        for (auto v : good_for_s[i])
            mn = min(mn, where[v]);
        if (mn != where[which[i]])
            return cout << "NO\n", 0;
    }

    cout << "YES\n";
    for (auto x : top_sort)
        cout << x + 1 << ' ';
    cout << '\n';
}