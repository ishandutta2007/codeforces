#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, d;
int a[Maxn];
map <int, int> M;

void Remove(int x)
{
    auto it = M.find(x);
    if (--it->second == 0)
        M.erase(it);
}

void Add(int x)
{
    auto it = M.find(x);
    if (it == M.end()) M.insert(make_pair(x, 1));
    else it->second++;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &d);
        M.clear();
        int res = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            Add(a[i] - a[i - 1] - 1);
        }
        for (int i = 1; i <= n; i++) {
            Remove(a[i] - a[i - 1] - 1);
            if (i < n) {
                Remove(a[i + 1] - a[i] - 1);
                Add(a[i + 1] - a[i - 1] - 1);
            }
            int lst = i == n? n - 1: n;
            Add(d - a[lst] - 1);
            res = max(res, M.begin()->first);
            Remove(d - a[lst] - 1);
            int mx = M.rbegin()->first;
            Remove(mx);
            Add((mx - 1) / 2);
            Add(mx / 2);
            res = max(res, M.begin()->first);
            Remove(mx / 2);
            Remove((mx - 1) / 2);
            Add(mx);
            if (i < n) {
                Remove(a[i + 1] - a[i - 1] - 1);
                Add(a[i + 1] - a[i] - 1);
            }
            Add(a[i] - a[i - 1] - 1);
        }
        printf("%d\n", res);
    }
    return 0;
}