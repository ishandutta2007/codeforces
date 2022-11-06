#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 10 ;

int T , n , k;
ll s[N] ;

int main() 
{
    scanf("%d" , &T) ;
    while(T --)
    {
        scanf("%d%d" , &n , &k) ;
        for(int i = n - k + 1; i <= n; i ++) scanf("%lld" , s + i) ;
        if (k == 1) {puts("YES") ; continue ;}
        for (int i = n ; i > n - k + 1 ; i --) s[i] = s[i] - s[i - 1] ;
        bool ok = 1 ;
        for (int i = n - k + 2 ; i < n ; i ++) ok &= (s[i] <= s[i + 1]) ;
        if (ok && s[n - k + 1] <= s[n - k + 2] * (n - k + 1)) puts("YES") ;
        else puts("NO") ;
    }

    return 0 ;
}