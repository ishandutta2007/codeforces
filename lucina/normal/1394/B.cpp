#include<random>
#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int const nax = 3e5 + 10;
using ull = uint64_t;
int n, m, k;
int ans = 0;
mt19937 rng(ull(new char()));
ull h[nax];
ull tot;
ull val[10][10];
vector <pair <int, int>> a[nax];

void brute (int x, ull cur) {
    if (x > k) {
        if (cur == 0)
            ++ ans;
    } else {
        for (int to = 1 ; to <= x ; ++ to) {
            brute(x + 1, cur ^ val[x][to]);
        }
    }
}


int main () {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1 ; i <= m ; ++ i) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        a[from].emplace_back(w, to);
    }

    for (int i = 1 ; i <= n ; ++ i)
        h[i] = rng(), tot ^= h[i];

    for (int i = 1 ; i <= n ; ++ i) {

        sort(a[i].begin(), a[i].end());
        for (int v = 0 ; v < a[i].size() ; ++ v) {
            val[a[i].size()][v + 1] ^= h[a[i][v].second];
        }
    }

    brute(1, tot);

    printf("%d\n", ans);
}