#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

double MAX_TIME = 1.2 * CLOCKS_PER_SEC;

int get_min(vec< int > a, int k) {
    sort(ALL(a));
    int sz = (int)a.size();
    vec< int > perm(sz);
    for(int i = 0;i < sz;i++) perm[i] = i;
    int ok = 0;
    while(clock() < MAX_TIME) {
        random_shuffle(ALL(perm));
        int pr = 0;
        for(int i : perm) {
            if(pr + a[i] <= k) {
                pr += a[i];
            }else {
                break;
            }
        }
        if(pr == k) {
            ok = 1;
        }
    }
    return k + !ok;
}

int get_max(vec< int > a, int k) {
    sort(ALL(a));
    reverse(ALL(a));
    int sz = (int)a.size();
    vec< int > x(sz), y(sz);
    for(int i = 0;k > 0 && i < sz;i++) {
        if(2 * k > a[i]) {
            x[i] = (a[i] / 2) * 2;
            y[i] = a[i] / 2;
            k -= a[i] / 2;
        }else {
            x[i] = 2 * k;
            y[i] = k;
            k = 0;
        }
    }
    for(int i = 0;k > 0 && i < sz;i++) {
        if(a[i] - x[i] > 0) {
            x[i]++;
            y[i]++;
            k--;
        }
    }
    int res = 0;
    for(int i = 0;i < sz;i++) {
        res += x[i];
    }
    return res;
}

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    vec< char > used(n + 1);
    vec< int > p(n + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
    }

    vec< int > a;
    a.reserve(n);

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        int u = i, cnt = 0;
        while(!used[u]) {
            used[u] = 1;
            u = p[u];
            cnt++;
        }
        a.push_back(cnt);
    }

    printf("%d %d\n", get_min(a, k), get_max(a, k));

    return 0;
}