#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int h, m, n;
int inset[Maxn], id[Maxn];

struct pos {
    int x;
    pos(int x = 0): x(x) {}
    bool operator <(const pos &p) const {
        return id[x] < id[p.x];
    }
};

set <pos> S[Maxn];
int siz[Maxn];
map <int, int> M;
ll res;

int main()
{
    scanf("%d %d %d", &h, &m, &n);
    for (int i = 0; i < h; i++) if (!id[i]) {
        int j = i;
        do {
            inset[j] = i; id[j] = S[i].size() + 1; S[i].insert(pos(j));
            j = (j + m) % h;
        } while (!id[j]);
        siz[i] = S[i].size();
    }
    while (n--) {
        char c;
        int v, hsh;
        scanf(" %c", &c);
        if (c == '+') {
            scanf("%d %d", &v, &hsh);
            set <pos>::iterator it = S[inset[hsh]].lower_bound(pos(hsh));
            if (it == S[inset[hsh]].end()) it = S[inset[hsh]].begin();
            res += (id[it->x] - id[hsh] + siz[inset[hsh]]) % siz[inset[hsh]];
            M[v] = it->x; S[inset[hsh]].erase(it);
        } else {
            scanf("%d", &v);
            S[inset[M[v]]].insert(pos(M[v])); M.erase(v);
        }
    }
    printf("%I64d\n", res);
    return 0;
}