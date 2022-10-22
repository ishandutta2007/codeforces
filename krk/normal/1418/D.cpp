#include <bits/stdc++.h>
using namespace std;

int n, q;
set <int> S;
map <int, int> M;

void addMap(int key)
{
    M[key]++;
}

void remMap(int key)
{
    if (--M[key] == 0)
        M.erase(key);
}

void Add(int key)
{
    auto it = S.lower_bound(key);
    if (it != S.begin()) {
        auto itp = it;
        itp--;
        if (it != S.end()) {
            remMap(*it - *itp);
            addMap(*it - key);
            addMap(key - *itp);
        } else addMap(key - *itp);
    } else if (it != S.end())
        addMap(*it - key);
    S.insert(key);
}

void Rem(int key)
{
    S.erase(key);
    auto it = S.lower_bound(key);
    if (it != S.begin()) {
        auto itp = it;
        itp--;
        if (it != S.end()) {
            addMap(*it - *itp);
            remMap(*it - key);
            remMap(key - *itp);
        } else remMap(key - *itp);
    } else if (it != S.end())
        remMap(*it - key);
}

int Get() { return M.empty()? 0: *S.rbegin() - *S.begin() - M.rbegin()->first; }

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        int p; scanf("%d", &p);
        Add(p);
    }
    printf("%d\n", Get());
    for (int i = 0; i < q; i++) {
        int t, x; scanf("%d %d", &t, &x);
        if (t == 0) Rem(x);
        else Add(x);
        printf("%d\n", Get());
    }
    return 0;
}