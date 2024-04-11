#include<bits/stdc++.h>
using namespace std;

int const nax = 2e5 + 1;
#define l first
#define r second
using segment = pair<int, int> ;

int n;
int com[nax * 2], topCom;
segment a[nax];


struct fenwick {
    static const int Sz = nax * 2;
    int bit[Sz];

    void update (int idx, int val) {
        for ( ; idx <= topCom ; idx += idx & -idx)
            bit[idx] += val;
    }

    int get (int idx) {
        int res  = 0 ;
        for (; idx > 0 ; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int get (int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }

    void clean () {
        for (int i = 1 ; i <= topCom ; ++ i)
            bit[i] = 0;
    }
};

fenwick f;
bool is_left[nax];
bool is_one[nax];
segment b[nax];
int savX[nax], savY[nax];

int where (int x) {
    return (int) (lower_bound(com + 1 , com + 1 + topCom, x) - com);
}

int main () {
    int T;
    scanf("%d", &T);
    for ( ; T -- ;) {
        scanf("%d", &n);
        topCom = 0;
        for (int i = 1 ; i <= n;  ++ i ) {
            scanf("%d %d", &a[i].l, &a[i].r);
            com[++ topCom] = a[i].l;
            com[++ topCom] = a[i].r;

            is_left[i] = is_one[i] = false;

        }
        sort(com + 1, com + topCom + 1);
        topCom = unique(com + 1, com + topCom + 1) - com - 1;

        int base = 0;

        sort(a + 1,  a + 1 + n);
        int curR = INT_MIN;

        for (int i = 1 ; i <= n ; ++ i) {

            if (a[i].l > curR)
                ++ base;
            curR = max(curR, a[i].r);

            savX[i] = where(a[i].l), savY[i] = where(a[i].r);

            int huh = f.get(savX[i]);

            if (huh == 0) {
                is_left[i] = true;
            } else if (huh == 1) is_one[i] = true;


            f.update(savX[i], 1);
            f.update(savY[i] + 1 ,  -1);
        }

        int mx = -1;

        f.clean();

        for (int i = n ; i >= 1 ; -- i) {
            if (is_one[i]) f.update(savX[i], 1);
            mx = max(mx, f.get(savX[i], savY[i]) - is_left[i] - is_one[i]);
        }

        printf("%d\n", mx + base);
        f.clean();
    }

}