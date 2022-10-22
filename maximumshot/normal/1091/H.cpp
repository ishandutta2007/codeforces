#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int MAXX = 2e5 + 5;

int pr[MAXX];

int main() {

    fill(pr, pr + MAXX, 1);

    pr[0] = pr[1] = 0;
    for(int i = 2;i * i < MAXX;i++) {
        if(!pr[i]) continue;
        for(int j = i * i;j < MAXX;j += i) {
            pr[j] = 0;
        }
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    vector< int > a;

    for(int i = 2;i < MAXX;i++) {
        if(pr[i]) {
            a.push_back(i);
        }
    }

    vector< int > turn;

    for(int p1 : a) {
        turn.push_back(p1);
        for(int p2 : a) {
            if(p1 * p2 > MAXX) break;
            turn.push_back(p1 * p2);
        }
    }

    sort(turn.begin(), turn.end());
//    turn.resize(unique(turn.begin(), turn.end()));

    int n, f;

    scanf("%d %d", &n, &f);

    vector< int > g(MAXX); // hm, mb grundy is small
    vector< bitset< MAXX > > used(179);

    for(int t : turn) {
        if(t == f) continue;
        used[0][t] = 1;
    }
    bitset< MAXX > bt;

    for(int t : turn) {
        if(t == f) continue;
        bt[t] = 1;
    }

    for(int i = 1;i < MAXX;i++) {
        while(used[ g[i] ][i]) g[i]++;
        used[ g[i] ] |= bt << i;
    }

    int res = 0;

    for(int i = 0;i < n;i++) {
        int r, w, b;
        scanf("%d %d %d", &r, &w, &b);
        res ^= g[w - r - 1];
        res ^= g[b - w - 1];
    }

    if(res == 0) {
        puts("Bob\nAlice");
    }else {
        puts("Alice\nBob");
    }

    return 0;
}