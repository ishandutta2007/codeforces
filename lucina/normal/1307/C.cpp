#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10 ;
int n, ct[27];
long long  ans;
char s[nax];
long long b[27][27] ;

int main () {
    scanf("%s", s + 1) ;
    n = strlen(s + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        ct[s[i] - 'a'] ++ ;
        ans = max (ans, (long long)(ct[s[i] - 'a']));
    }
    memset(ct, 0, sizeof(ct));
    for (int i = n ; i >= 1 ; i --) {
        int cur = s[i] - 'a';
        for (int v = 0 ; v < 26 ; ++ v) {
            b[cur][v] += ct[v];
            ans = max(ans, b[cur][v]);
        }
        ct[cur] ++;
    }
    printf("%lld\n", ans);
}
/*
    Good Luck
        -Lucina
*/