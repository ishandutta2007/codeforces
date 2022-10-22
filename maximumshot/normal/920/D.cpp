#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 5005;

int n, k, V;
int a[N];
bitset< N > dp[N];
bitset< N > fr[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &k, &V);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    {
        int sum = 0;
        for(int i = 1;i <= n;i++) {
            sum += a[i];
        }
        if(sum < V) {
            puts("NO");
            return 0;
        }
    }

    if(V % k == 0) {
        puts("YES");
        for(int i = 1;i < n;i++) {
            if(!a[i]) continue;
            printf("%d %d %d\n", (a[i] + k - 1) / k, i, n);
            a[n] += a[i];
            a[i] = 0;
        }
        if(V > 0) {
            printf("%d %d %d\n", V / k, n, 1);
        }
        return 0;
    }

    dp[0][0] = 1;

    for(int i = 1;i <= n;i++) {
        int d = a[i] % k;
        for(int j = 0;j < k;j++) {
            if(dp[i - 1][j]) {
                dp[i][j] = 1;
                fr[i][j] = 0;
            }
            if(!d) continue;
            int j2 = (j + k - d) % k;
            if(dp[i - 1][j2]) {
                dp[i][j] = 1;
                fr[i][j] = 1;
            }
        }
    }

    if(!dp[n][V % k]) {
        puts("NO");
        return 0;
    }

    puts("YES");

    vec< int > way;
    vec< char > used(n + 1);

    for(int j = V % k, i = n;i >= 1;i--) {
        if(fr[i][j]) {
            way.push_back(i);
            used[i] = 1;
            j = (j - a[i] % k + k) % k;
        }
    }

    assert(!way.empty());

    for(int it = 1;it < (int)way.size();it++) {
        int i = way[it];
        assert(a[i] > 0);
        printf("%d %d %d\n", (a[i] + k - 1) / k, i, way.front());
        a[way.front()] += a[i];
        a[i] = 0;
    }

    int tmp = -1;

    for(int i = 1;i <= n;i++) {
        if(!used[i]) {
            tmp = i;
            break;
        }
    }

    if(tmp != -1) {
        for(int i = 1;i <= n;i++) {
            if(used[i] || i == tmp || a[i] == 0) continue;
            printf("%d %d %d\n", (a[i] + k - 1) / k, i, tmp);
            a[tmp] += a[i];
            a[i] = 0;
        }
    }

    if(tmp != -1 && a[tmp] >= k) {
        printf("%d %d %d\n", a[tmp] / k, tmp, way.front());
        a[way.front()] += (a[tmp] / k) * k;
        a[tmp] %= k;
    }

    tmp = way.front() == 1 ? 2 : 1;

    assert(a[way.front()] % k == V % k);
    assert(a[way.front()] >= V);

    if(a[way.front()] > V) {
        printf("%d %d %d\n", (a[way.front()] - V) / k, way.front(), tmp);
    }

    return 0;
}