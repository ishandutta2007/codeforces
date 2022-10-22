#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;

    scanf("%d", &n);

    vec< ll > a(n);

    int g = 0;

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        a[i] = x;
        if(i == 0) {
            g = x;
        }else {
            g = __gcd(g, x);
        }
    }

    if(g > 1) {
        puts("YES\n0");
        return 0;
    }

    int res = 0;

    for(int i = 0;i < n;i++) {
        if(a[i] % 2 == 0) continue;
        int j = i;
        while(j < n && a[j] % 2 == 1) j++;
        j--;
        int len = j - i + 1;
        if(len % 2) {
            res += len / 2 + 2;
        }else {
            res += len / 2;
        }
        i = j;
    }

    printf("YES\n%d\n", res);

    return 0;
}