#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10 ;
int n, a[nax];
char s[nax];

void solve () {
    /// consider each group of << and >>
    scanf("%d %s", &n, s + 2);
    iota(a + 1 ,  a + 1 + n, 1);
    reverse(a + 1 ,  a + 1 + n);
    for (int i = 2 ; i <= n ; i ++) {
        int j = i ;
        if (s[i] == '<') {
            while (j <= n && s[j] == s[i])
                j ++;
            reverse(a + i - 1, a + j);
            j -- ;
        }
        i = j ;
    }

    for (int i = 1 ; i <= n ; i ++) {
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }

    iota(a + 1 , a + 1 + n , 1);
    for (int i = 2 ; i <= n ; ++ i) {
        int j = i;
        if (s[i] == '>') {
            while (j <= n && s[j] == s[i])
                j ++;
            reverse(a + i - 1 , a + j) ;
            j --;
        }
        i = j;
    }
    for (int i = 1 ; i <= n ; i ++) {
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
}

int main () {
    int T;
    for (cin >> T ; T -- ; ) {
        solve() ;
    }
}
/*
    Good Luck
        -Lucina
*/