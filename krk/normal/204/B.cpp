#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;

int n;
set <int> was;
map <int, int> f, b;
int need;
int best;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        was.insert(l); f[l]++;
        if (l != r) { was.insert(r); b[r]++; }
    }
    need = (n + 1) / 2;
    best = Inf;
    for (set <int>::iterator it = was.begin(); it != was.end(); it++)
        if (f[*it] + b[*it] >= need) best = min(best, max(0, need - f[*it]));
    if (best == Inf) printf("-1\n");
    else printf("%d\n", best);
    return 0;
}