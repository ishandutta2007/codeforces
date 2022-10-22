#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n, x, res, cnt;
bool used[N];

int main() {

    scanf("%d", &n);

    for(int i = 0;i < n+n;i++) {
        scanf("%d", &x);
        if(used[x]) cnt--;
        else {
            cnt++;
            used[x] = 1;
        }
        res = max(res, cnt);
    }

    printf("%d\n", res);

    return 0;
}