#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod1 = inf + 7;
int const mod2 = inf + 9;

int const P = 37;
pii const pp = make_pair(P, P);
int const Q = 43;
pii const qq = make_pair(Q, Q);
pii const ee = make_pair(1, 1);

inline pii sum(pii a, pii b) {
    return make_pair(
        (a.first + b.first) % mod1,
        (a.second + b.second) % mod2
    );
}

inline pii mul(pii a, pii b) {
    return make_pair(
        (1ll * a.first * b.first) % mod1,
        (1ll * a.second * b.second) % mod2
    );
}

int const N = 100005;
int const M = 1000005;
int const C = 500005;
int const mod = inf + 7;

pii pwp[N];
pii pwq[C];
int fact[M];

void init() {
    pwp[0] = ee;
    for(int i = 1;i < N;i++) {
        pwp[i] = mul(pwp[i - 1], pp);
    }
    pwq[0] = ee;
    for(int i = 1;i < C;i++) {
        pwq[i] = mul(pwq[i - 1], qq);
    }
    fact[0] = 1;
    for(int i = 1;i < M;i++) {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    }
}

int n, m;
pii H[M];
int arr[C], sz;
int cnt[M];

int main() {

    init();

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &sz);
        set< int > s;
        for(int j = 1;j <= sz;j++) {
            scanf("%d", &arr[j]);
            cnt[arr[j]]++;
            s.insert( arr[j] );
        }
        for(int x : s) {
            H[x] = sum(H[x], mul(pwp[i], pwq[ cnt[x] ]));
        }
        for(int j = 1;j <= sz;j++) {
            cnt[arr[j]]--;
        }
    }

    vec< pair< pii, int > > mas;
    mas.reserve(m);

    for(int i = 1;i <= m;i++) {
        mas.push_back( make_pair(H[i], i) );
    }

    sort(ALL(mas));

    int tot_res = 1;

    for(int i = 0;i < m;i++) {
        int j = i;
        while(j < m && mas[i].first == mas[j].first) j++;
        j--;
        int cur_cnt = j - i + 1;
        tot_res = (1ll * tot_res * fact[cur_cnt]) % mod;
        i = j;
    }

    printf("%d\n", tot_res);

    return 0;
}