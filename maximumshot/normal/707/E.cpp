#include <bits/stdc++.h>

#include <time.h>
#include <random>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

struct Fenwick {
    int n;
    vec< ll > fen;
    Fenwick() {
        n = 0;
    }
    Fenwick(int nn) {
        n = nn;
        fen.resize(n + 1);
    }
    void put(int pos, int val) {
        for(int cur = pos;cur <= n;cur |= (cur + 1))
            fen[cur] += val;
    }
    ll get(int pos) {
        ll res = 0;
        for(int cur = pos;cur > 0;cur = (cur & (cur + 1)) - 1)
            res += fen[cur];
        return res;
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

bool solve() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vec< vec< pair< pii, int > > > add(m + 1);
    for(int i = 1;i <= m;i++) add[i].reserve(n);

    for(int len, i, j, w, iter = 0;iter < k;iter++) {
        scanf("%d", &len);
        for(int iter2 = 0;iter2 < len;iter2++) {
            scanf("%d %d %d", &i, &j, &w);
            add[j].push_back({{i, w}, iter});
        }
    }

    int q;
    scanf("%d", &q);

    vec< char > type(q);
    vec< int > sw(q);
    vec< pii > ask(q);
    vec< vec< ll > > res(2005, vec< ll >(k));
    vec< vec< int > > era(m + 1), ins(m + 1);
    vec< int > ide(q);

    char buffer[10];

    for(int i, x1, y1, x2, y2, iter = 0;iter < q;iter++) {
        scanf("%s", buffer);
        if(string(buffer) == "SWITCH") {
            scanf("%d", &i);
            type[iter] = 0;
            sw[iter] = i - 1;
        }else {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            type[iter] = 1;
            ask[iter] = {x1, x2};
            ins[y1].push_back(iter);
            era[y2].push_back(iter);
            static int rectange_size = 0;
            ide[iter] = rectange_size++;
        }
    }

    vec< Fenwick > fen(k, Fenwick(n));

    for(int pos, value, id, l, r, j = 1;j <= m;j++) {
        for(int iter : ins[j]) {
            tie(l, r) = ask[iter];
            for(int kk = 0;kk < k;kk++) {
                res[ide[iter]][kk] -= fen[kk].get(l, r);
            }
        }
        for(auto _iter : add[j]) {
            tie(pos, value) = _iter.first;
            id = _iter.second;
            fen[id].put(pos, value);
        }
        for(int iter : era[j]) {
            tie(l, r) = ask[iter];
            for(int kk = 0;kk < k;kk++) {
                res[ide[iter]][kk] += fen[kk].get(l, r);
            }
        }
    }

    vec< char > state(k, 1);

    for(int iter = 0;iter < q;iter++) {
        if(type[iter] == 0) {
            state[sw[iter]] ^= 1;
        }else {
            ll result = 0;
            for(int i = 0;i < k;i++) {
                if(state[i])
                    result += res[ide[iter]][i];
            }
            printf("%I64d\n", result);
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}