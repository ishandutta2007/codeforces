#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

vec< int > t, pu;

void push(int v) {
    if(pu[v]) {
        pu[v * 2 + 1] = pu[v * 2 + 2] = 1;
        t[v * 2 + 1] = t[v * 2 + 2] = 0;
        pu[v] = 0;
    }
}

void up(int v) {
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

void upd(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        pu[v] = 1;
        t[v] = 0;
    }else {
        push(v);
        int tm = (tl + tr) >> 1;
        if(l <= tm) upd(v * 2 + 1, tl, tm, l, r);
        if(r > tm) upd(v * 2 + 2, tm + 1, tr, l, r);
        up(v);
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        pu[v] = 0;
        t[v] = 1;
    }else {
        int tm = (tl + tr) >> 1;
        build(v * 2 + 1, tl, tm);
        build(v * 2 + 2, tm + 1, tr);
        up(v);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return t[v];
    }else {
        push(v);
        int tm = (tl + tr) >> 1, res = 0;
        if(l <= tm) res += get(v * 2 + 1, tl, tm, l, r);
        if(r > tm) res += get(v * 2 + 2, tm + 1, tr, l, r);
        up(v);
        return res;
    }
}

bool solve() {

    int n, q;

    scanf("%d %d", &n, &q);

    vec< int > cur(n + 1);
    vec< vec< int > > mess(n + 1);

    t.resize(4 * q);
    pu.resize(4 * q);

    build(0, 0, q - 1);

    for(int total = 0, x, type, iter = 0;iter < q;iter++) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d", &x);
            mess[x].push_back(total++);
        }else if(type == 2) {
            scanf("%d", &x);
            for(int pos;cur[x] < (int)mess[x].size();cur[x]++) {
                pos = mess[x][cur[x]];
                upd(0, 0, q - 1, pos, pos);
            }
        }else {
            scanf("%d", &x);
            upd(0, 0, q - 1, 0, x - 1);
        }
        if(total > 0) printf("%d\n", get(0, 0, q - 1, 0, total - 1));
        else printf("0\n");
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}