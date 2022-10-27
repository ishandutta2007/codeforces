#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10 ;
int n;
char s[nax];

int main () {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int bal = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        bal += s[i] == '('  ? 1 : -1;
    }
    if (bal != 0) {
        return !printf("-1");
    }
    int ans = 0;
    int cur_bal = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cur_bal += s[i] == '(' ? 1 : -1;
        if (cur_bal < 0) {
            int j = i;
            ++ ans;
            for (j = i + 1 ; j <= n ; ++ j) {
                cur_bal += s[j] == '(' ? 1 : -1;
                ++ ans;
                if (cur_bal == 0) break;
            }
            i = j;
        }
    }
    printf("%d\n", ans);
}
/*
    Good Luck
        -Lucina
*/