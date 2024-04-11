#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int q;
map <ll, set <ii> > S;
map <ii, int> M;
int all;

void Add(const ii &p, int val)
{
    auto it = M.find(p);
    if (it == M.end()) M.insert(make_pair(p, val));
    else it->second += val;
}

void Rem(const ii &p, int val)
{
    auto it = M.find(p);
    if (it->second == val) M.erase(it);
    else it->second -= val;
}

int Get(const ii &p)
{
    auto it = M.find(p);
    return it == M.end()? 0: it->second;
}

ii Fix(const ii &p)
{
    int g = gcd(p.first, p.second);
    return ii(p.first / g, p.second / g);
}

void insertSet(set <ii> &S, const ii &p)
{
    Add(Fix(p), 1);
    for (auto u: S) {
        ii got = ii(u.first + p.first, u.second + p.second);
        Add(Fix(got), 2);
    }
    S.insert(p);
}

void removeSet(set <ii> &S, const ii &p)
{
    S.erase(p);
    Rem(Fix(p), 1);
    for (auto u: S) {
        ii got = ii(u.first + p.first, u.second + p.second);
        Rem(Fix(got), 2);
    }
}

void Insert(const ii &p)
{
    ll ind = ll(p.first) * p.first + ll(p.second) * p.second;
    insertSet(S[ind], p);
    all++;
}

void Remove(const ii &p)
{
    ll ind = ll(p.first) * p.first + ll(p.second) * p.second;
    removeSet(S[ind], p);
    all--;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        int t, x, y; scanf("%d %d %d", &t, &x, &y);
        if (t == 1) Insert(ii(x, y));
        else if (t == 2) Remove(ii(x, y));
        else printf("%d\n", all - Get(Fix(ii(x, y))));
    }
    return 0;
}