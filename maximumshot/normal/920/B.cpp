#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int T = 5005;

void solve() {
    int n;
    scanf("%d", &n);
    vec< int > add[T];
    vec< int > del[T];
    vec< int > res(n);
    for(int l, r, i = 0;i < n;i++) {
        scanf("%d %d", &l, &r);
        add[l].push_back(i);
        del[r].push_back(i);
    }
    set< int > Q;
    for(int t = 0;t < T;t++) {
        for(int id : add[t]) {
            Q.insert(id);
        }
        if(!Q.empty()) {
            int id = *Q.begin();
            Q.erase(Q.begin());
            res[id] = t;
        }
        for(int id : del[t]) {
            Q.erase(id);
        }
    }
    for(int i = 0;i < n;i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int t;

    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}