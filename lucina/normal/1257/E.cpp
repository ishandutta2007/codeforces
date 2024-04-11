#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int x, y, z, w, a[nax], n, s[3];

int main(){
    scanf("%d %d %d", &x, &y, &z);
    n = x + y + z;
    for(int i = 1 ;i <= x ; i ++){
        scanf("%d", &w);
    }
    for(int i = 1 ; i <= y ; i++){
        scanf("%d", &w);
        a[w] = 1;
    }
    for(int i = 1 ;i <= z ; i++){
        scanf("%d", &w);
        a[w] = 2;
    }
    int ans = 1e9 + 7, keep = 0;
    keep = ans ;
    for(int i = 1 ; i <= n  + 1; i++){
        keep = min(keep, s[1] + x - s[0]);
        ans = min(ans, keep + y - s[1] +  s[2]);
        s[a[i]] ++ ;
    }
    printf("%d\n", ans);
}

    /**
    Assume that the suffix is
                    i , i + 1 , .... , n
    -> The later part can be easily calculated
    Look back to prefix
    it means that every number < i
    is in 1 or 2
    [        ] [         ] and [ exclude part ]
    if you want prefix to be 1 ... k
    The number of move is exactly
    [number of element <= k in 2] + [number of element > k  and < i in 1]
    and the latter part is exactly equal to
    [number of element >= i in 1] + [number of element >= i in 2] + [number of element < i  in 3]

    ->  [number of element <= k in 2] + [number of element > k in 1]
    + [number of element >= i in 2] + [number of element < i  in 3]
    */