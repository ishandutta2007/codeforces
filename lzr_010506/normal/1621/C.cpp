#include <bits/stdc++.h>

const int MAX_N = 1e4 + 10 ;

std::vector<int> lst ;

bool ap[MAX_N] ;
int T , n , cnt , p[MAX_N] ;

int getnum(int x) {
    printf("? %d\n" , x) ;
    fflush(stdout) ;
    
    ++cnt ;
    int t ; scanf("%d" , &t) ;
    return t ;
}

void rollback(int pl , int x) {
    int len = lst.size() ;

    x %= len ; x = (len - x) % len ; (++x) %= len ;
    for (int i = 0 ; i < len ; ++i) {
        p[pl] = lst[x] ; pl = lst[x] ; (++x) %= len ;
    }
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) ap[i] = 0 ;

        cnt = 0 ;
        for (int i = 1 ; i <= n ; ++i) {
            if (ap[i]) continue ;
            
            int stp = cnt ; lst.clear() ;
            for (; ;) {
                int x = getnum(i) ;
                if (ap[x]) break ;
                ap[x] = 1 ; lst.push_back(x) ;
            }

            rollback(i , stp) ;
        }

        printf("! ") ;
        for (int i = 1 ; i <= n ; ++i) printf("%d " , p[i]) ;
        printf("\n") ; fflush(stdout) ;
    }
    
    return 0 ;
}