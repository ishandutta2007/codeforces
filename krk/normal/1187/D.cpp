#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n;
int a[Maxn];
map <int, int> M;
int my[Maxn];
vector <int> V[Maxn];
int b[Maxn];

void Insert(int key, int val)
{
    map <int, int>::iterator it = M.upper_bound(key);
    if (it != M.begin()) {
        it--;
        if (it->second <= val) return;
    }
    it = M.lower_bound(key);
    while (it != M.end() && val <= it->second)
        M.erase(it++);
    M[key] = val;
}

int Get(int key)
{
    map <int, int>::iterator it = M.upper_bound(key);
    if (it != M.begin()) {
        it--;
        return it->second;
    }
    return Maxn;
}

bool Solve()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        V[i].clear();
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        V[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    M.clear();
    for (int i = n - 1; i >= 0; i--)
        if (V[b[i]].empty()) return false;
        else {
            int ind = V[b[i]].back(); V[b[i]].pop_back();
            if (Get(b[i]) < ind) return false;
            Insert(b[i], ind);
        }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}