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

int const N = 200005;

int n, s;
int a[N];
bool used[N];

int main() {

    scanf("%d %d", &n, &s);

    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

    int res = 0;

    if(a[s] != 0) {
        res++;
        a[s] = 0;
    }

    if(n == 1) {
        printf("%d\n", res);
        return 0;
    }

    for(int i = 1;i <= n;i++) {
        if(i == s) continue;
        if(a[i] == 0) {
            a[i] = inf;
        }
    }

    sort(a + 1, a + n + 1);

//    for(int i = 1;i <= n;i++) {
//        cout << a[i] << " ";
//    }

//    cout << "\n";

    int tot = inf;

    for(int pos, cur = 0, mx = 1;mx < n;mx++) {
        pos = lower_bound(a + 1, a + n + 1, mx) - a;
        if(pos >= 1 && pos <= n && a[pos] == mx) used[mx] = 1;
        else cur++;
        int ost = n + 1 - (upper_bound(a + 1, a + n + 1, mx) - a);
        //cout << mx << " : " << cur << " " << ost << "\n";
        int tmp = res;
        if(cur <= ost) {
            tmp += ost;
        }else {
            tmp += cur;
        }
        tot = min(tot, tmp);
    }

    printf("%d\n", tot);

    return 0;
}