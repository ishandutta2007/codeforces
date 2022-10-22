#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n, m, d;
pii a[N];
pii b[N];
ll pa[N];
ll pb[N];
ll ca[N];
ll cb[N];

bool cmp(pii x, pii y) {
    if(x.first > y.first) {
        return true;
    }else if(x.first < y.first) {
        return false;
    }else { // x.first == y.first
        return x.second < y.second;
    }
}

ll get_sum(int l, int r) {
    return pb[r] - pb[l - 1];
}

int main() {

    scanf("%d %d %d", &n, &m, &d);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }

    for(int i = 1;i <= m;i++) {
        scanf("%d %d", &b[i].first, &b[i].second);
    }

    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + m + 1, cmp);

    for(int i = 1;i <= n;i++) {
        pa[i] = pa[i - 1] + a[i].second;
        ca[i] = ca[i - 1] + a[i].first;
    }

    for(int i = 1;i <= m;i++) {
        pb[i] = pb[i - 1] + b[i].second;
        cb[i] = cb[i - 1] + b[i].first;
    }

    ll result = 0;

    for(int i = 1;i <= n;i++) {
        int bl = 1;
        int br = m;
        int bm;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(pb[bm] + pa[i] <= d) bl = bm;
            else br = bm - 1;
        }
        int bp;
        if(bl < br && pb[br] + pa[i] <= d) bp = br;
        else if(pb[bl] + pa[i] <= d) bp = bl;
        else continue;
        result = max(result, ca[i] + cb[bp]);
    }

    cout << result << "\n";

    return 0;
}