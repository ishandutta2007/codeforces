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

int const N = 3005;

int n, p, s;
pair< pii, int > a[N];
int dp[N][N];

bool solve() {
    scanf("%d %d %d", &n, &p, &s);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i].first.first);
        a[i].second = i;
    }

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i].first.second);
    }

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            dp[i][j] = -inf;
        }
    }

    sort(a, a + n);
    reverse(a, a + n);

    dp[0][1] = a[0].first.first;
    dp[0][0] = a[0].first.second;

    for(int i = 1;i < n;i++) {
        for(int cnt = 0;cnt <= i + 1;cnt++) {
            if(cnt > 0 && dp[i - 1][cnt - 1] != -inf) dp[i][cnt] = max(dp[i][cnt], dp[i - 1][cnt - 1] + a[i].first.first);
            if(dp[i - 1][cnt] != -inf) dp[i][cnt] = max(dp[i][cnt], dp[i - 1][cnt] + a[i].first.second);
        }
    }

    pii res = {-1, -1};

    for(int i = p - 1;i < p + s;i++) {
        if(dp[i][p] == -inf) continue;
        int need = p + s - i - 1;
        vec< int > mas;
        for(int j = i + 1;j < n;j++) mas.push_back(a[j].first.second);
        sort(ALL(mas));
        reverse(ALL(mas));
        int tmp = dp[i][p];
        for(int j = 0;j < need;j++)
            tmp += mas[j];
        res = max(res, {tmp, i});
    }

    printf("%d\n", res.first);

    vec< int > res_a, res_b;
    vec< pii > mas;

    for(int i = res.second + 1;i < n;i++) {
        mas.push_back({a[i].first.second, a[i].second});
    }

    sort(ALL(mas));
    reverse(ALL(mas));

    for(int i = 0;i < p + s - res.second - 1;i++) {
        res_b.push_back(mas[i].second);
    }

    for(int i = res.second, j = p;;) {
        if(i > 0) {
            if(j > 0 && dp[i][j] == dp[i - 1][j - 1] + a[i].first.first) {
                res_a.push_back(a[i].second);
                i--;
                j--;
            }else {
                res_b.push_back(a[i].second);
                i--;
            }
        }else {
            if(j == 0) res_b.push_back(a[i].second);
            else res_a.push_back(a[i].second);
            break;
        }
    }

    sort(ALL(res_a));
    sort(ALL(res_b));

    for(int x : res_a) printf("%d ", x + 1);
    printf("\n");
    for(int x : res_b) printf("%d ", x + 1);
    printf("\n");

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}