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

int const MAX_VAL = 100005;
int const N = 100005;

int res = 1;
int n;
int a[N];
int cnt[N];

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    for(int x = 2;x < MAX_VAL;x++) {
        int tmp = 0;
        for(int y = x;y < MAX_VAL;y += x) {
            tmp += cnt[y];
        }
        res = max(res, tmp);
    }

    printf("%d\n", res);

    return 0;
}