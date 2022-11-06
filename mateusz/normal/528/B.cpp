#include <bits/stdc++.h>
using namespace std;
const int N = 200005, czapa = 131072 * 2;
pair<int, int> tab[N], tab2[N];
int n;
int gdzie[N];
int drz[2 * czapa + 5];
void insert(int poz, int w) {
    poz += czapa;
    while(poz >= 1) {
        drz[poz] = max(drz[poz], w);
        poz /= 2;
    }
}

int query(int poza, int pozb) {
    poza += czapa;
    pozb += czapa;
    if(poza > pozb) {
        return 0;
    }
    int ret = max(drz[poza], drz[pozb]);
    while(poza / 2 != pozb / 2) {
        if(poza % 2 == 0) {
            ret = max(ret, drz[poza + 1]);
        }
        if(pozb % 2 == 1) {
            ret = max(ret, drz[pozb - 1]);
        }
        poza /= 2;
        pozb /= 2;
    }
    return ret;
}
int main() {
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &tab[i].first, &tab[i].second);
    }
    sort(tab + 1, tab + 1 + n);
    for(int i = 1; i <= n; i++) {
        tab2[i].first = tab[i].first - tab[i].second;
        tab2[i].second = i;
    }
    sort(tab2 + 1, tab2 + 1 + n);
    for(int i = 1; i <= n; i++) {
        gdzie[tab2[i].second] = i;
    }
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        int x = tab[i].first + tab[i].second;
        int poc = 1;
        int kon = n;
        int res = n + 1;
        while(poc <= kon) {
            int sr = (poc + kon) / 2;
            if(tab2[sr].first >= x) {
                res = sr;
                kon = sr - 1;
            } else {
                poc = sr + 1;
            }
        }
        int dp = query(res, n) + 1;
        ans = max(ans, dp);
        insert(gdzie[i], dp);
    }
    printf("%d\n", ans);
}