#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n, t, k;
int a[N];
int b[N];
pii id[N];

int main() {

    scanf("%d %d %d", &n, &t, &k);

    for(int i = 1;i <= t;i++) scanf("%d", &a[i]);
    a[0] = 1;

    if(k < a[t]) {
        puts("-1");
        return 0;
    }else {
        k -= a[t];
    }

    for(int tmp = 0, i = 0;i <= t;i++) {
        // tmp + 1 .. tmp + a[i]
        id[i] = make_pair(tmp + 1, tmp + a[i]);
        tmp += a[i];
        //cout << id[i].first << " .. " << id[i].second << "\n";
    }

    int mn = 0;
    int mx = 0;

    for(int i = 1;i <= t;i++) {
        mn += b[i] = max(0, a[i - 1] - a[i]);
        mx += a[i - 1] - 1;
    }

    for(int i = t - 1;i >= 1;i--) {
        b[i] += b[i + 1];
    }

    if(mn > k || mx < k) {
        puts("-1");
        return 0;
    }

    //cout << mn << " .. " << mx << "\n";

    vec< pii > edge;

    for(int cur = 0, i = 1;i <= t;i++) {
        // cur + x + b[i] <= k
        // x <= k - b[i] - cur
        int x = min(k - (i < t ? b[i + 1] : 0) - cur, a[i - 1] - 1);
        x = max(x, 0);
        //cout << i << " : " << x << "\n";
        int ql, qr;
        tie(ql, qr) = id[i - 1];
        // ql .. qr - x
        int ql2, qr2;
        tie(ql2, qr2) = id[i];
        //cout << "(" << ql << ", " << qr << ") ; (" << ql2 << ", " << qr2 << ")\n";
        int len = qr - ql + 1 - x;
        int len2 = qr2 - ql2 + 1;
        for(int j = 0;j < len;j++) {
            //cout << ql + j << " - " << ql2 + j << "\n";
            edge.push_back( make_pair( ql + j, ql2 + j ) );
        }
        for(int j = len;j < len2;j++) {
            //cout << ql << " - " << ql2 + j << "\n";
            edge.push_back( make_pair( ql, ql2 + j ) );
        }
        cur += x;
    }

    printf("%d\n", n);

    for(pii i : edge) {
        printf("%d %d\n", i.first, i.second);
    }

    return 0;
}