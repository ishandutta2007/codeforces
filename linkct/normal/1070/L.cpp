#include <bitset>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 2003;
int n, m;
bitset<MAXN> a[MAXN];
int b[MAXN];
int f[MAXN];
vector<int> e[MAXN];
void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        a[i] = 0, e[i].clear();
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    bool ok = true;
    for (int i = 0; i < n; ++i)
        if (e[i].size() % 2 != 0)
            ok = false;
    if (ok) {
        puts("1");
        for (int i = 0; i < n; ++i)
            printf("1%c", i == (n - 1) ? '\n' : ' ');
        return;
    }
    for (int i = 0; i < n; ++i) {
        b[i] = e[i].size() % 2;
        if (e[i].size() % 2 == 1)
            a[i].set(i);
        for (int j : e[i])
            a[i].set(j);
    }
    for (int i = 0; i < n; ++i) {
        int p = i;
        while (p < n && !a[p][i])
            ++p;
        if (p == n)
            continue;
        if (p != i) {
            swap(a[i], a[p]);
            swap(b[i], b[p]);
        }
        for (int j = i + 1; j < n; ++j)
            if (a[j][i]) {
                a[j] ^= a[i];
                b[j] ^= b[i];
            }
    }
    memset(f, 0, sizeof(f));
    for (int i = n - 1; i >= 0; --i)
        if (a[i][i]) {
            f[i] = b[i];
            for (int j = 0; j < i; ++j)
                if (a[j][i]) {
                    a[j].reset(i);
                    b[j] ^= b[i];
                }
        }
        else {
            assert(a[i].none());
            for (int j = 0; j < i; ++j)
                if (a[j][i])
                    a[j].reset(i);
        }
    puts("2");
    for (int i = 0; i < n; ++i)
        printf("%d%c", f[i] + 1, i == (n - 1) ? '\n' : ' ');
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        run();
    return 0;
}