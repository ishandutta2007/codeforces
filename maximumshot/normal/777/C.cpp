#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    vec< vec< int > > a(n, vec< int >(m));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vec< int > mx(n, -1);

    for(int j = 0;j < m;j++) {
        for(int i = 0;i < n;i++) {
            int t = i;
            while(t + 1 < n && a[t][j] <= a[t + 1][j]) t++;
            // i .. t
            mx[i] = max(mx[i], t);
            i = t;
        }
    }

    for(int i = 1;i < n;i++) {
        mx[i] = max(mx[i], mx[i - 1]);
    }

    int k;

    scanf("%d", &k);

    for(int l, r, i = 0;i < k;i++) {
        scanf("%d %d", &l, &r);
        l--, r--;
        if(mx[l] >= r) {
            puts("Yes");
        }else {
            puts("No");
        }
    }

    return 0;
}