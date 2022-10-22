#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;
int const C = 1e6 + 5;

int n, A;
int c[N];
int cnt[C];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &A);

    set< pii > q;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &c[i]);
        if(c[i] != A) {
            q.insert(make_pair(0, c[i]));
        }
    }

    int ca = 0;

    for(int i = 1;i <= n;i++) {
        if(c[i] == A) {
            ca++;
        }else {
            if(q.count(make_pair(cnt[c[i]], c[i]))) {
                q.erase(make_pair(cnt[c[i]], c[i]));
                cnt[c[i]]++;
                q.insert(make_pair(cnt[c[i]], c[i]));
            }
        }
        while(!q.empty() && q.begin()->first < ca) {
            q.erase(q.begin());
        }
    }

    if(q.empty()) {
        puts("-1");
    }else {
        printf("%d\n", q.begin()->second);
    }

    return 0;
}