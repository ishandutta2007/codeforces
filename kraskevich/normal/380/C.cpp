#include <bits/stdc++.h>

using namespace std;

struct bit
{
    vector<int> f;
    bit(int n) {
        f.assign(n, 0);
    }
    int get(int i) {
        int res = 0;
        while (i >= 0)
        {
            res += f[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
    void put(int i, int by) {
        for (; i < f.size(); i = (i | (i + 1)))
            f[i] += by;
    }
};

const int N = (int)1e6 + 10;
vector<int> at[N];
vector<int> ids[N];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int n = s.length();
    vector<int> pos(n, -1);
    stack<int> q;
    for (int i = 0; i < n; i++)
        if (s[i] == '(')
            q.push(i);
        else {
            if (!q.empty()) {
                pos[i] = q.top();
                q.pop();
            }
        }
    bit tree(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        at[r].push_back(l);
        ids[r].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (pos[i] >= 0)
            tree.put(pos[i], 1);
        for (int j = 0; j < at[i].size(); j++) {
            int l = at[i][j];
            int id = ids[i][j];
            ans[id] = tree.get(l, i);
        }
    }
    for (int i = 0; i < m; i++)
        cout << 2 * ans[i] << "\n";

    return 0;
}