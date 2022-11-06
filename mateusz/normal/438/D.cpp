#include <bits/stdc++.h>

using namespace std;
const int N = 100005, czapa = 131072;
int tab[N];
long long drz[2 * czapa];
pair<int, int> maks[2 * czapa];
int n, m;
long long query(int poza, int pozb) {
    poza += czapa;
    pozb += czapa;
    long long ret = drz[poza];
    if(poza != pozb) {
        ret += drz[pozb];
    }
    while(poza / 2 != pozb / 2) {
        if(poza % 2 == 0) {
            ret += drz[poza + 1];
        }
        if(pozb % 2 == 1) {
            ret += drz[pozb - 1];
        } 
        poza /= 2;
        pozb /= 2;
    }
    return ret;
}

void insert(int poz, int w) {
    poz += czapa;
    drz[poz] = w;
    maks[poz] = {w, poz - czapa};
    poz /= 2;
    while(poz >= 1) {
        drz[poz] = drz[poz * 2] + drz[poz * 2 + 1];
        maks[poz] = max(maks[poz * 2], maks[poz * 2 + 1]);
        poz /= 2;
    }
}

void ogar(int poz, int x) {
    while(maks[poz].first >= x) {
        insert(maks[poz].second, maks[poz].first % x);
    }
}

void setModulo(int poza, int pozb, int x) {
    poza += czapa;
    pozb += czapa;
    ogar(poza, x);
    ogar(pozb, x);
    while(poza / 2 != pozb / 2) {
        if(poza % 2 == 0)
            ogar(poza + 1, x);
        if(pozb % 2 == 1)
            ogar(pozb - 1, x);
        poza /= 2;
        pozb /= 2;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        insert(i, tab[i]);
    }
    int type, l, r, x;
    for(int i = 1; i <= m; i++) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d %d", &l, &r);
            printf("%I64d\n", query(l, r));
        } else if(type == 2) {
            scanf("%d %d %d", &l, &r, &x);
            setModulo(l, r, x);
        } else {
            scanf("%d %d", &l, &r);
            insert(l, r);
        }
    }
    return 0;
}