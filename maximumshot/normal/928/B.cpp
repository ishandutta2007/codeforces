#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, k;
int a[N];
int dp[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int l, r, i = 1;i <= n;i++) {
        l = i - min(k, i - 1);
        r = i + min(k, n - i);
        if(!a[i]) {
            dp[i] = r - l + 1;
        }else {
            int j = a[i];
            int jr = j + min(k, n - j);
            if(jr < l) {
                dp[i] = dp[j] + r - l + 1;
            }else {
                dp[i] = dp[j] + r - jr;
            }
        }
        printf("%d ", dp[i]);
    }

    puts("");

    return 0;
}