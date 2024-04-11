#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

struct Unit {
    int hp;
    int dmg;

    void read() {
        scanf("%d %d", &hp, &dmg);
    }

    bool operator<(const Unit &other) const {
        return hp - dmg > other.hp - other.dmg;
    }
};

const int N = 2e5 + 5;

int n, a, b;
Unit u[N];

void b0() {
    ll result = 0;
    for(int i = 1;i <= n;i++) {
        result += u[i].dmg;
    }
    printf("%lld\n", result);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &a, &b);

    for(int i = 1;i <= n;i++) {
        u[i].read();
    }

    if(b == 0) {
        b0();
        return 0;
    }

    sort(u + 1, u + n + 1);

    int ptr = 0;

    while(ptr < b && ptr < n && u[ptr + 1].hp >= u[ptr + 1].dmg) ptr++;

    // 1 .. ptr

    ll res = -inf64;
    ll hlp = 0;

    for(int i = 1;i <= ptr;i++) {
        hlp += u[i].hp;
    }

    for(int i = ptr + 1;i <= n;i++) {
        hlp += u[i].dmg;
    }

    res = hlp;

    for(int i = 1;i <= ptr;i++) {
        ll tmp = hlp;
        tmp -= u[i].hp;
        tmp += max((ll(u[i].hp) << a), ll(u[i].dmg));
        res = max(res, tmp);
    }

    for(int i = ptr + 1;i <= n;i++) {
        ll tmp = hlp;
        tmp -= u[i].dmg;
        tmp += max((ll(u[i].hp) << a), ll(u[i].dmg));
        if(ptr == b) {
            tmp -= u[ptr].hp;
            tmp += u[ptr].dmg;
        }
        res = max(res, tmp);
    }

    printf("%lld\n", res);

    return 0;
}