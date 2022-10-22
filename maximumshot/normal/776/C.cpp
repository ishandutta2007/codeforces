#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;
ll const X = 1ll * inf * 1000 * 1000;

int n, k;
int a[N];

int main() {

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    set< ll > q;

    for(ll value = 1, iter = 0;iter < 100 && value < X;iter++, value *= k) {
        q.insert(value);
    }

    map< ll, int > cnt;

    cnt[0] = 1;

    ll cur = 0;
    ll res = 0;

    for(int i = 1;i <= n;i++) {
        cur += a[i];
        for(ll x : q) {
            // cur - need == x
            ll need = cur - x;
            if(cnt.count(need)) {
                res += cnt[need];
            }
        }
        cnt[cur]++;
    }

    cout << res << "\n";

    return 0;
}