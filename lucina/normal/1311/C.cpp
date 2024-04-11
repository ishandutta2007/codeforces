#include<cstdio>
#include<algorithm>
using ll = long long ;
int const nax = 3e5 + 10;
int n, m;
int a[nax], b[nax];
ll ct[26];
char s[nax];
int sum[nax][26];

void solve () {
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1 ; i <= m ; ++ i)
        scanf("%d", b + i);
    std::fill(ct , ct + 26 , 0);
    std::fill(sum[0], sum[0] + 26 , 0);
    for (int i = 1 ; i <= n ; ++ i) {
        int v = s[i] - 'a';
        for (int j = 0 ; j < 26 ; ++ j)
            sum[i][j] = sum[i - 1][j];
        ++ sum[i][v];
    }
    for (int i = 1 ; i <= m ; ++ i) {
        for (int j = 0 ; j < 26 ; ++ j) {
            ct[j] += sum[b[i]][j];
        }
    }
    for (int i = 1 ; i <= n ; ++ i)
        ct[s[i] - 'a'] ++ ;
    for (int i = 0 ; i < 26 ; ++ i)
        printf("%lld ", ct[i]);
    printf("\n");
}

int main () {
    int T;
    for (scanf("%d", &T) ; T -- ; ) {
        solve();
    }
}