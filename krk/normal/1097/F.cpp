#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxp = 311;
const int Maxb = 62;
const int Maxv = 7001;
const int Maxs = 10;

int mx[Maxv];
bool squaref[Maxv];
int st[Maxs], en[Maxs];
ll divs[Maxv][Maxp];
ll a[Maxn][Maxp];
int n, q;
char res[1000005];
int rlen;

int main()
{
    for (int i = 2; i < Maxv; i++) if (mx[i] == 0)
        for (int j = i; j < Maxv; j += i) mx[j] = i;
    for (int i = 1; i < Maxv; i++) {
        int num = i;
        bool ok = true;
        while (num > 1 && ok) {
            int cur = mx[num];
            int my = 0;
            while (mx[num] == cur) { num /= cur; my++; }
            ok = my < 2;
        }
        squaref[i] = ok;
    }
    int tot = 0;
    en[0] = 112;
    for (int i = 1; i < Maxs; i++) {
        st[i] = en[i - 1] + 1;
        int pnt = st[i] * Maxb;
        for (int j = i; j < Maxv; j += i)
            if (squaref[j / i]) {
                divs[j][pnt / Maxb] ^= 1ll << ll(pnt % Maxb);
                pnt++;
            }
        en[i] = (pnt - 1) / Maxb;
    }
    for (int i = Maxv - 1; i > 0; i--) {
        divs[i][i / Maxb] ^= 1ll << ll(i % Maxb);
        for (int j = i + i; j < Maxv; j += i)
            for (int z = 0; z < Maxp; z++)
                divs[j][z] ^= divs[i][z];
    }
    scanf("%d %d", &n, &q);
    while (q--) {
        int typ, x, y, z; scanf("%d %d %d", &typ, &x, &y);
        if (typ == 1) {
            for (int i = 0; i < Maxp; i++)
                a[x][i] = divs[y][i];
        } else if (typ == 2) {
            scanf("%d", &z);
            for (int i = 0; i < Maxp; i++)
                a[x][i] = (a[y][i] ^ a[z][i]);
        } else if (typ == 3) {
            scanf("%d", &z);
            for (int i = 0; i < Maxp; i++)
                a[x][i] = (a[y][i] & a[z][i]);
        } else {
            bool cur = false;
            int got = 0;
            if (y < Maxs) {
                for (int i = st[y]; i <= en[y]; i++)
                    got += __builtin_popcountll(a[x][i]);
                cur = got % 2;
            } else for (int i = y; i < Maxv; i += y) if (squaref[i / y])
                        cur ^= bool(a[x][i / Maxb] & 1ll << ll(i % Maxb));
            res[rlen++] = int(cur) + '0';
        }
    }
    res[rlen] = '\0';
    printf("%s\n", res);
    return 0;
}