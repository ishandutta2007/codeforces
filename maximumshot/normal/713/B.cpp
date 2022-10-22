#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int ask(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

pair< pii, pii > get(int n) {
    int bl, br, bm;
    int L, R, U, D;

    bl = 1;
    br = n;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(ask(1, bm, n, n) == 2) bl = bm;
        else br = bm - 1;
    }

    if(bl < br && ask(1, br, n, n) == 2) L = br;
    else L = bl;

    bl = 1;
    br = n;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(ask(1, 1, n, bm) == 2) br = bm;
        else bl = bm + 1;
    }

    if(bl < br & ask(1, 1, n, bl) == 2) R = bl;
    else R = br;

    bl = 1;
    br = n;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(ask(1, 1, bm, n) == 2) br = bm;
        else bl = bm + 1;
    }

    if(bl < br && ask(1, 1, bl, n) == 2) U = bl;
    else U = br;

    bl = 1;
    br = n;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(ask(bm, 1, n, n) == 2) bl = bm;
        else br = bm - 1;
    }

    if(bl < br && ask(br, 1, n, n) == 2) D = br;
    else D = bl;

    return {{L, R}, {D, U}};
}

pair< pii, pii > find(int x1, int y1, int x2, int y2, int Le = inf, int Ri = -inf, int Dn = inf, int Up = -inf) {

    //cout << "find " << x1 << " " << y1 << ", " << x2 << " " <<  y2 << " !\n";
    //cout << Le << " " << Ri << " " << Dn << " " << Up << "\n";

    int bl, br, bm;
    int L, R, U, D;

    bl = y1;
    br = y2;

    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (ask(x1, bm, x2, y2) >= 1) bl = bm;
        else br = bm - 1;
    }

    if (bl < br && ask(x1, br, x2, y2) >= 1) L = br;
    else L = bl;


    bl = y1;
    br = y2;

    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (ask(x1, y1, x2, bm) >= 1) br = bm;
        else bl = bm + 1;
    }

    if (bl < br & ask(x1, y1, x2, bl) >= 1) R = bl;
    else R = br;

    bl = x1;
    br = x2;

    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (ask(x1, y1, bm, y2) >= 1) br = bm;
        else bl = bm + 1;
    }

    if (bl < br && ask(x1, y1, bl, y2) >= 1) U = bl;
    else U = br;


    bl = x1;
    br = x2;

    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (ask(bm, y1, x2, y2) >= 1) bl = bm;
        else br = bm - 1;
    }

    if (bl < br && ask(br, y1, x2, y2) >= 1) D = br;
    else D = bl;

    if(Le != -1 && Le != y1) L = y1;
    if(Ri != -1 && Ri != y2) R = y2;
    if(Dn != -1 && Dn != x1) D = x1;
    if(Up != -1 && Up != x2) U = x2;

    return {{L, R}, {D, U}};
}

bool solve() {

    int n;
    scanf("%d", &n);

    pair< pii, pii > g = get(n); // 16 * 4 == 64
    int L, R, U, D;

    tie(L, R) = g.first;
    tie(D, U) = g.second;

    if(U == D) {
        int bl, br, bm;
        bl = L;
        br = R;
        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(ask(U, L, U, bm) == 0) bl = bm + 1;
            else br = bm;
        }
        int cur;
        if(bl < br && ask(U, L, U, bl) == 1) cur = bl;
        else cur = br;
        printf("! %d %d %d %d %d %d %d %d\n", U, L, U, cur, U, cur + 1, U, R);
        fflush(stdout);
        return true;
    }

    if(L == R) {
        int bl, br, bm;
        bl = D;
        br = U;
        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(ask(D, L, bm, L) == 0) bl = bm + 1;
            else br = bm;
        }
        int cur;
        if(bl < br && ask(D, L, bl, L) == 1) cur = bl;
        else cur = br;
        printf("! %d %d %d %d %d %d %d %d\n", D, L, cur, L, cur + 1, L, U, L);
        fflush(stdout);
        return true;
    }

    //cout << "[" << L << " .. " << R << "]\n";
    //cout << "[" << D << " .. " << U << "]\n";

    pair< pii, pii > g1;
    pair< pii, pii > g2;

    if(ask(D + 1, L, U, R)) {
        g1 = find(D + 1, L, U, R, -1, -1, -1, -1);
        g2 = find(D, L, U, R, g1.first.first, g1.first.second, g1.second.first, g1.second.second);
        //cout << "ok\n";
    }else {
        g1 = find(D, L + 1, U, R, -1, -1, -1, -1);
        g2 = find(D, L, U, R, g1.first.first, g1.first.second, g1.second.first, g1.second.second);
    }

    printf("! %d %d %d %d %d %d %d %d\n", g1.second.first, g1.first.first, g1.second.second, g1.first.second,
                                          g2.second.first, g2.first.first, g2.second.second, g2.first.second);
    fflush(stdout);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}