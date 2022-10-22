#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;

int n, m, k, q;
vector <int> my[Maxn];
map <int, ll> M[Maxn];
int mx;
vector <int> cols;
ll res = Inf;

void Update(map <int, ll> &M, int key, ll val)
{
    map <int, ll>::iterator it = M.find(key);
    if (it == M.end()) M.insert(make_pair(key, val));
    else it->second = min(it->second, val);
}

void giveUp(int r, int c, ll val, bool one = false)
{
    if (r == mx) { res = min(res, val); return; }
    int ind = lower_bound(cols.begin(), cols.end(), c) - cols.begin();
    if (ind < cols.size())
        Update(M[r + 1], cols[ind], val + cols[ind] - c + 1);
    if (one) return;
    if (ind > 0) {
        ind--;
        Update(M[r + 1], cols[ind], val + c - cols[ind] + 1);
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 0; i < k; i++) {
        int r, c; scanf("%d %d", &r, &c);
        my[r].push_back(c);
        mx = max(mx, r);
    }
    for (int i = 0; i < q; i++) {
        int c; scanf("%d", &c);
        cols.push_back(c);
    }
    sort(cols.begin(), cols.end());
    M[1][1] = 0;
    for (int i = 1; i <= mx; i++) {
        sort(my[i].begin(), my[i].end());
        for (map <int, ll>::iterator it = M[i].begin(); it != M[i].end(); it++)
            if (my[i].empty()) giveUp(i, it->first, it->second, true);
            else if (it->first <= my[i][0]) {
                ll val = it->second + my[i].back() - it->first;
                giveUp(i, my[i].back(), val);
            } else if (my[i].back() <= it->first) {
                ll val = it->second + it->first - my[i][0];
                giveUp(i, my[i][0], val);
            } else {
                ll val = it->second + 2 * (it->first - my[i][0]) + (my[i].back() - it->first);
                giveUp(i, my[i].back(), val);
                val = it->second + 2 * (my[i].back() - it->first) + (it->first - my[i][0]);
                giveUp(i, my[i][0], val);
            }
    }
    cout << res << endl;
    return 0;
}