#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3005;

int n, m;
int p[N], c[N];
int cnt[N];
vec< int > ar[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &p[i], &c[i]);
        cnt[p[i]]++;
        ar[p[i]].push_back(i);
    }

    for(int i = 1;i <= m;i++) {
        sort(ALL(ar[i]), [&](int u, int v){
            return c[u] < c[v];
        });
    }

    ll res = inf64;

    for(int x = max(1, cnt[1]);x <= n;x++) {
        int cur = cnt[1];
        ll tmp = 0;
        vec< int > tot;
        for(int j = 2;j <= m;j++) {
            int hlp = cnt[j], ptr = 0;
            while(hlp >= x) {
                tmp += c[ ar[j][ptr] ];
                ptr++;
                hlp--;
                cur++;
            }
            for(int it = ptr;it < (int)ar[j].size();it++) {
                tot.push_back(c[ ar[j][it] ]);
            }
        }
        if(cur > x) continue;
        sort(ALL(tot));
        for(int ad : tot) {
            if(cur == x) break;
            cur++;
            tmp += ad;
        }
        if(tmp < res) res = tmp;
    }

    printf("%lld\n", res);

    return 0;
}