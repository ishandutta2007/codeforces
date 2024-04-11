#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000005;

char str[50];
int n, q;
ll BIT[Maxn];
map <ii, int> M;
ll incol[Maxn];

void Add(int ind, ll val)
{
    for (int i = ind; i <= n; i += i & -i)
        BIT[i] += val;
}

void Add(int l, int r, ll val)
{
    Add(l, val);
    Add(r + 1, -val);
}

ll Get(int ind)
{
    ll res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int getColour(int ind)
{
    auto it = M.lower_bound(ii(ind + 1, 0));
    it--;
    return it->second;
}

void insertColour(int l, int r, int col)
{
    auto it = M.lower_bound(ii(l + 1, 0));
    it--;
    if (it->first.first < l) {
        int tmpl = it->first.first;
        int tmpr = it->first.second;
        int tmpcol = it->second;
        M.erase(it);
        M.insert(make_pair(ii(tmpl, l - 1), tmpcol));
        M.insert(make_pair(ii(l, tmpr), tmpcol));
    }
    it = M.lower_bound(ii(l, 0));
    while (it != M.end() && it->first.first <= r)
        if (it->first.second <= r) {
            Add(it->first.first, it->first.second, incol[it->second]);
            M.erase(it++);
        } else {
            int tmpl = it->first.first;
            int tmpr = it->first.second;
            int tmpcol = it->second;
            M.erase(it);
            M.insert(make_pair(ii(r + 1, tmpr), tmpcol));
            Add(tmpl, r, incol[tmpcol]);
            break;
        }
    M.insert(make_pair(ii(l, r), col));
    Add(l, r, -incol[col]);
}

int main()
{
    scanf("%d %d", &n, &q);
    M.insert(make_pair(ii(1, n), 1));
    while (q--) {
        scanf("%s", str);
        if (str[0] == 'C') {
            int l, r, c; scanf("%d %d %d", &l, &r, &c);
            insertColour(l, r, c);
        } else if (str[0] == 'A') {
            int c, x; scanf("%d %d", &c, &x);
            incol[c] += x;
        } else if (str[0] == 'Q') {
            int ind; scanf("%d", &ind);
            ll res = Get(ind) + incol[getColour(ind)];
            printf("%I64d\n", res);
        }
    }
    return 0;
}