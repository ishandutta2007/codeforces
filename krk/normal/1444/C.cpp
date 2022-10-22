#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 500005;

int n, m, k;
int c[Maxn];
map <ii, vector <ii> > M;
int par[Maxn], col[Maxn], siz[Maxn];
vector <ii> P;
int valid;
bool fallgroup[Maxn];

ii getPar(int x)
{
    int p = x, c = 0;
    while (par[p] != p) {
        c ^= col[p];
        p = par[p];
    }
    return ii(p, c);
}

bool unionSet(int a, int b)
{
    ii para = getPar(a), parb = getPar(b);
    if (para.first == parb.first) return para.second != parb.second;
    if (siz[para.first] < siz[parb.first]) { swap(a, b); swap(para, parb); }
    P.push_back(ii(para.first, parb.first));
    siz[para.first] += siz[parb.second];
    col[parb.first] = (para.second ^ parb.second ^ 1);
    par[parb.first] = para.first;
    return true;
}

void Undo(int cnt)
{
    while (P.size() > cnt) {
        int a = P.back().first, b = P.back().second;
        siz[a] -= siz[b];
        col[b] = 0;
        par[b] = b;
        P.pop_back();
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        par[i] = i;
        col[i] = 0;
        siz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (c[a] > c[b]) swap(a, b);
        auto it = M.find(ii(c[a], c[b]));
        if (it != M.end()) it->second.push_back(ii(a, b));
        else {
            vector <ii> tmp = {ii(a, b)};
            M.insert(make_pair(ii(c[a], c[b]), tmp));
        }
    }
    valid = k;
    for (map <ii, vector <ii> >::iterator it = M.begin(); it != M.end(); it++)
        if (it->first.first == it->first.second)
            for (int i = 0; i < it->second.size() && !fallgroup[it->first.first]; i++) {
                int a = it->second[i].first;
                int b = it->second[i].second;
                if (!unionSet(a, b)) {
                    fallgroup[it->first.first] = true;
                    valid--;
                }
            }
    ll res = ll(valid) * (valid - 1) / 2;
    for (map <ii, vector <ii> >::iterator it = M.begin(); it != M.end(); it++)
        if (it->first.first != it->first.second) {
            int ga = it->first.first;
            int gb = it->first.second;
            if (fallgroup[ga] || fallgroup[gb]) continue;
            int cnt = P.size();
            bool fall = false;
            for (int i = 0; i < it->second.size() && !fall; i++) {
                int a = it->second[i].first;
                int b = it->second[i].second;
                if (!unionSet(a, b))
                    fall = true;
            }
            if (fall) res--;
            Undo(cnt);
        }
    printf("%I64d\n", res);
    return 0;
}