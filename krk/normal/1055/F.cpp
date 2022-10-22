#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 2000005;
const int Maxb = 62;

struct node {
    int cnt;
    int ch[2];
    int match;
    node() { cnt = 0; ch[0] = ch[1] = match = -1; }
};

int n;
ll k;
ll my[Maxn];
int in[Maxn];
int pnt;
node V[Maxm];

void createNew()
{
    V[pnt].cnt = 0;
    V[pnt].ch[0] = V[pnt].ch[1] = V[pnt].match = -1;
    if (++pnt == Maxm) pnt = 0;
}

int getLst() { return pnt == 0? Maxm - 1: pnt - 1; }

int Get(int ind) { return ind != -1? V[ind].cnt: 0; }

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 2; i <= n; i++) {
        int p; ll mask; scanf("%d %I64d", &p, &mask);
        my[i] = (my[p] ^ mask);
    }
    createNew();
    int r = getLst();
    V[r].cnt = n;
    V[r].match = r;
    for (int i = 1; i <= n; i++)
        in[i] = r;
    ll cur = 0;
    for (int i = Maxb - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) if (in[j] != -1) {
            int ind = bool(my[j] & 1ll << ll(i));
            if (V[in[j]].match == -1) { in[j] = -1; continue; }
            if (V[in[j]].ch[ind] == -1) {
                createNew(); V[in[j]].ch[ind] = getLst();
            }
            V[V[in[j]].ch[ind]].cnt++;
        }
        ll col = 0;
        for (int j = 1; j <= n; j++) if (in[j] != -1) {
            int ind = bool(my[j] & 1ll << ll(i));
            if (V[in[j]].match != -1)
                col += Get(V[V[in[j]].match].ch[ind]);
        }
        int give = col < k;
        if (give) {
            cur |= 1ll << ll(i);
            k -= col;
        }
        for (int j = 1; j <= n; j++) if (in[j] != -1) {
            int ind = bool(my[j] & 1ll << ll(i));
            if (V[in[j]].match != -1)
                V[V[in[j]].ch[ind]].match = V[V[in[j]].match].ch[ind ^ give];
            in[j] = V[in[j]].ch[ind];
        }
    }
    printf("%I64d\n", cur);
    return 0;
}