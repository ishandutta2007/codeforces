#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxk = 1 << 19;

struct node {
    int ch[2];
    node() { ch[0] = ch[1] = 0; }
};

int n, k;
vector <node> V;
int my[Maxk];
int res[Maxk];

void createNew() { V.push_back(node()); }

int getLst() { return int(V.size()) - 1; }

int Get(int tr, int lvl, int mask, bool mx)
{
    if (lvl < 0) return 0;
    int one = bool(mask & 1 << lvl);
    int a = one;
    int b = 1 - one;
    if (mx) swap(a, b);
    if (V[tr].ch[a]) return ((a ^ one) << lvl) | Get(V[tr].ch[a], lvl - 1, mask, mx);
    return ((b ^ one) << lvl) | Get(V[tr].ch[b], lvl - 1, mask, mx); 
}

int main()
{
    scanf("%d %d", &n, &k);
    createNew();
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        createNew();
        my[a] = getLst();
    }
    fill(res, res + (1 << k), Inf);
    for (int b = 1; b <= k; b++) {
        for (int i = 0; i < 1 << k; i += 1 << b) {
            int A = i, B = i + (1 << b - 1);
            if (my[A] && my[B]) {
                for (int z = 0; z < 1 << b - 1; z++) {
                    res[z] = min(res[z], (1 << b - 1) + Get(my[B], b - 2, z, false) - Get(my[A], b - 2, z, true));
                    res[z | (1 << b - 1)] = min(res[z | (1 << b - 1)], (1 << b - 1) + Get(my[A], b - 2, z, false) - Get(my[B], b - 2, z, true));
                }
            }
            if (my[A] || my[B]) {
                createNew();
                int nw = getLst();
                V[nw].ch[0] = my[A];
                V[nw].ch[1] = my[B];
                my[A] = nw;
            }
        }
        if (b < k)
            for (int i = 0; i < 1 << b; i++)
                res[i | (1 << b)] = min(res[i | (1 << b)], res[i]);
    }
    for (int i = 0; i < 1 << k; i++)
        printf("%d%c", res[i], i + 1 < (1 << k)? ' ': '\n');
    return 0;
}