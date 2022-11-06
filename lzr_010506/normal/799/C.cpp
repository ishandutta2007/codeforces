#include <bits/stdc++.h>
using namespace std;
inline int getmax(int& to, const int& from)
{
    to = (to < from ? from : to);
}
const int N = 1e5 + 10;
int n, have[2], Mx[2], ans, b[N], p[N], t[N];
vector <pair <int, int> > st[2];
vector <int> mx[2][2];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	n = read();
	have[0] = read();
	have[1] = read();
    for (int i = 0; i < n; i ++)
    {
        b[i] = read();
        p[i] = read();
        char c;
        cin >> c;
        t[i] = (c == 'D');
        if (have[t[i]] >= p[i]) getmax(Mx[t[i]], b[i]);
    }
    if (Mx[0] && Mx[1]) ans = Mx[0] + Mx[1];
    for (int i = 0; i < n; i ++) st[t[i]].push_back({p[i], i});
    for (int j = 0; j < 2; j ++)
    {
        sort(st[j].begin(), st[j].end());
        if (st[j].empty()) continue;
        mx[j][0].resize(st[j].size(), -1),
        mx[j][1].resize(st[j].size(), -1);

        mx[j][0].front() = st[j].front().second;
        for (int i = 1; i < st[j].size(); i ++)
        {
            mx[j][0][i] = mx[j][0][i - 1], mx[j][1][i] = mx[j][1][i - 1];
            int &f = mx[j][0][i], &s = mx[j][1][i], idx = st[j][i].second;
            if (b[s] < b[idx]) s = idx;
            if (b[s] > b[f]) swap(f, s);
        }
    }

    for (int j = 0; j < 2; j ++)
        for (int i = 0; i < st[j].size(); i ++)
        {
            if (have[j] < st[j][i].first) continue;
            int left = have[j] - st[j][i].first, now, idx = st[j][i].second;
            now = upper_bound(st[j].begin(), st[j].end(), make_pair(left, N))
                    - st[j].begin() - 1;
            if (now < 0) continue;
            if (mx[j][0][now] != idx) getmax(ans, b[idx] + b[mx[j][0][now]]);
            else if (mx[j][1][now] != -1) getmax(ans, b[idx] + b[mx[j][1][now]]);
        }

    cout << ans;
}