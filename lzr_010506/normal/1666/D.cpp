#include <bits/stdc++.h>

const int MAX_N = 1e4 + 10 , MAX_M = 'Z' + 10 ;

std::queue<int> a[MAX_M] ;

int n ;
char s1[MAX_N] , s2[MAX_N] ;

int main() {
    scanf("%d" , &n) ;
    for (; n-- ;) {
        scanf("%s %s" , s1 , s2) ;
        int l1 = strlen(s1) , l2 = strlen(s2) ;

        std::reverse(s1 + 0 , s1 + l1) ; std::reverse(s2 + 0 , s2 + l2) ;
        for (int i = 'A' ; i <= 'Z' ; ++i)
            for (; !a[i].empty() ;) a[i].pop() ;
        for (int i = 0 ; i < l1 ; ++i) a[(int)s1[i]].push(i) ;

        bool ok = 1 ; int pre = -1 ;
        for (int i = 0 ; i < l2 && ok ; ++i) {
            int nw = s2[i] ;
            if (a[nw].empty()) ok = 0 ;
            else {
                int x = a[nw].front() ; a[nw].pop() ;
                if (x < pre) ok = 0 ;
                else pre = x ;
            }
        }

        if (ok) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}