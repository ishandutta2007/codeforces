#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m;
int a[Maxn];
map <int, int> M;

void Add(int key, int val)
{
    auto it = M.upper_bound(key); it--;
    if (it->second <= val) return;
    it = M.lower_bound(key);
    while (it != M.end() && it->second >= val)
        M.erase(it++);
    M.insert(make_pair(key, val));
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        M.clear();
        M.insert(make_pair(1, 1000000007));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            Add(i, a[i]);
        }
        while (m--) {
            int k, d; scanf("%d %d", &k, &d);
            a[k] -= d;
            Add(k, a[k]);
            printf("%d%c", int(M.size()), m? ' ': '\n');
        }
    }
    return 0;
}