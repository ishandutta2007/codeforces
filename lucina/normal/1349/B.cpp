#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
 
int n;
int a[nax];
int k;
 
bool solve () {
    
    scanf("%d %d", &n, &k);
    
    bool has = false;
    
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        
        if (a[i] == k) has = true;
        
        if (a[i] >= k) a[i] = 1;
        else a[i] = 0;
    }
    
    if (!has) return false;
    if (n == 1) return true;
    
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = i + 1 ; j - i <= 2 && j <= n ; ++ j)
            if (a[i] && a[j]) return true;
    }
    
    return false;
}
 
int main () {
    
    int T;
    
    for (scanf("%d", &T) ; T -- ;) {
        puts(solve() ? "yes" : "no");
    }
}