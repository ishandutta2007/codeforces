#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 3005;

char s[N];
int n;
int dp[N];
int from[N];

bool check(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return false;
    }else {
        return true;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%s", s);
    n = strlen(s);

    dp[0] = 1;
    from[0] = -1;

    for(int i = 1;i < n;i++) {
        dp[i] = dp[i - 1] + 1;
        from[i] = i - 1;
        for(int j = i;j >= 0;j--) {
            if(j + 2 <= i) {
                if(check(s[j]) && check(s[j + 1]) && check(s[j + 2])) {
                    if(s[j] != s[j + 1] || s[j] != s[j + 2] || s[j + 1] != s[j + 2]) {
                        break;
                    }
                }
            }
            if(dp[i] > (j > 0 ? dp[j - 1] : 0) + 1) {
                dp[i] = (j > 0 ? dp[j - 1] : 0) + 1;
                from[i] = j - 1;
            }
        }
    }

    vec< int > res;

    for(int i = n - 1;i >= 0;i = from[i]) {
        res.push_back(i);
    }

    reverse(ALL(res));

    for(int i = 0;i < (int)res.size();i++) {
        int l = i > 0 ? res[i - 1] + 1 : 0;
        int r = res[i];
        for(int j = l;j <= r;j++) {
            printf("%c", s[j]);
        }
        printf(" ");
    }

    printf("\n");

    return 0;
}