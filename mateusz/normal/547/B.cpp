#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 5;
const int N = 200005, czapa = 131072 * 2;
int n;
int a[N];
int tab[N];
int ans[N];
int drz[2 * czapa], drz2[2 * czapa];
int krotnosc[N];
bool cmp(int x, int y) {
    if(a[x] == a[y]) {
        return x < y;
    }
    return a[x] < a[y];
}

void insert(int w) {
    int poz = w + czapa;
    drz[poz] = w;
    poz /= 2;
    while(poz >= 1) {
        drz[poz] = max(drz[poz * 2], drz[poz * 2 + 1]);
        poz /= 2;
    }
}

void usun(int w) {
    int poz = w + czapa;
    drz[poz] = 0;
    poz /= 2;
    while(poz >= 1) {
        drz[poz] = max(drz[poz * 2], drz[poz * 2 + 1]);
        poz /= 2;
    }
}

//drz2
void dodaj(int poz) {
    poz += czapa;
    while(poz >= 1) {
        drz2[poz] = 1;
        poz /= 2;
    }
}
int wDolLewo(int poz) {
    if(poz >= czapa) {
        return poz - czapa;
    }
    if(drz2[poz * 2 + 1] == 1) {
        return wDolLewo(2 * poz + 1);
    } else {
        return wDolLewo(2 * poz);
    }
}
int naLewo(int poz) {
    poz += czapa;
    while(poz % 2 == 0 || drz2[poz - 1] == 0) {
        poz /= 2;
    }
    return wDolLewo(poz - 1);
}
int wDolPrawo(int poz) {
    if(poz >= czapa) {
        return poz - czapa;
    }
    if(drz2[poz * 2] == 1) {
        return wDolPrawo(2 * poz);
    } else {
        return wDolPrawo(2 * poz + 1);
    }
}
int naPrawo(int poz) {
    poz += czapa;
    while(poz % 2 == 1 || drz2[poz + 1] == 0) {
        poz /= 2;
    }
    return wDolPrawo(poz + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        tab[i] = i;
    }
    for(int i = 0; i <= n; i++) {
        ans[i] = INF;
    }
    sort(tab + 1, tab + 1 + n, cmp);
    dodaj(0);
    dodaj(n + 1);
    insert(n);
    krotnosc[n]++;
    for(int i = 1; i <= n; i++) {
        int w = tab[i];
        int x = naLewo(w);
        int y = naPrawo(w);
        krotnosc[y - x - 1]--;
        if(krotnosc[y - x - 1] == 0) {
            usun(y - x - 1);
        }
        krotnosc[w - x - 1]++;
        krotnosc[y - w - 1]++;
        insert(w - x - 1);
        insert(y - w - 1);
        dodaj(w);
        ans[drz[1] + 1] = min(ans[drz[1] + 1], a[w]);
    }
    for(int i = 1; i <= n; i++) {
        ans[i] = min(ans[i - 1], ans[i]);
        printf("%d ", ans[i]);
    }
    return 0;
}