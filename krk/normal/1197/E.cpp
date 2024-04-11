#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int mod = 1000000007;
const int Inf = 1000000007;

int n;
map <int, int> mn;
ii p[Maxn];
map <int, ii> M;
vector <ii> add[Maxn], rem[Maxn];
ii res = ii(Inf, 1);

void Add(int key, int val)
{
    map <int, ii>::iterator it = M.find(key);
    if (it == M.end()) M.insert(make_pair(key, ii(1, val)));
    else {
        it->second.first++;
        it->second.second = (it->second.second + val) % mod;
    }
}

void Rem(int key, int val)
{
    map <int, ii>::iterator it = M.find(key);
    if (it->second.first == 1) M.erase(it);
    else {
        it->second.first--;
        it->second.second = (it->second.second - val + mod) % mod;
    }
}

void Update(const ii &p)
{
    if (p.first < res.first) res = p;
    else if (p.first == res.first)
        res.second = (res.second + p.second) % mod;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        swap(p[i].first, p[i].second);
    }
    sort(p, p + n);
    mn[Inf] = Inf;
    int cur = Inf;
    for (int i = n - 1; i >= 0; i--) {
        cur = min(cur, p[i].second);
        mn[p[i].first] = cur;
    }
    add[0].push_back(ii(0, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < add[i].size(); j++)
            Add(add[i][j].first, add[i][j].second);
        for (int j = 0; j < rem[i].size(); j++)
            Rem(rem[i][j].first, rem[i][j].second);
        ii g = ii(M.begin()->first, M.begin()->second.second);
        g.first += p[i].first;
        map <int, int>::iterator it = mn.lower_bound(p[i].second);
        int lef = lower_bound(p, p + n, ii(p[i].second, 0)) - p;
        int rig = lower_bound(p, p + n, ii(it->second, 0)) - p;
        if (it->second >= Inf) Update(g);
        if (lef < rig) {
            g.first -= p[i].second;
            add[lef].push_back(g);
            rem[rig].push_back(g);
        }
    }
    printf("%d\n", res.second);
    return 0;
}