#include <bits/stdc++.h>

using namespace std;

const int N = 100005, czapa = 131072;

long long drz[2 * czapa];
int n, r[N], h[N];
int tab[N], pom[N];

void insert(int poz, long long w) {
    poz += czapa;
    while (poz >= 1) {
        drz[poz] = max(drz[poz], w);
        poz /= 2;
    }
}

long long query(int poza, int pozb) {
    poza += czapa;
    pozb += czapa;
    long long ret = max(drz[poza], drz[pozb]);
    while (poza / 2 != pozb / 2) {
        if (poza % 2 == 0) {
            ret = max(ret, drz[poza + 1]);
        }
        if (pozb % 2 == 1) {
            ret = max(ret, drz[pozb - 1]);
        }
        poza /= 2;
        pozb /= 2;
    }
    return ret;
}

long long V(long long r, long long h) {
    return r * r * h;
}

bool cmp(int a, int b) {
    return V(r[a], h[a]) < V(r[b], h[b]);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> h[i];
        tab[i] = i;
    }

    sort(tab + 1, tab + 1 + n, cmp);

    int in = 0;
    for (int i = 1; i <= n; i++) {
        if (V(r[tab[i]], h[tab[i]]) != V(r[tab[i - 1]], h[tab[i - 1]])) {
            in++;
        }
        pom[tab[i]] = in;
    }

    for (int i = 1; i <= n; i++) {
        int rr = r[i];
        int hh = h[i];
        long long v = (long long)rr * (long long)rr * hh;
        long long best = query(0, pom[i] - 1);
        insert(pom[i], best + v);
    }

    cout << fixed << setprecision(10) << (long double)query(1, n) * 3.14159265358979323846264338328L << endl;

    return 0;
}