#include<bits/stdc++.h>
using namespace std;
/// fft? hell no!, but maybe a good place to practice implementing modulus fft
int n, m, p;

int main () {
    scanf("%d %d %d", &n, &m, &p);
    
    int f = -1, g = -1;
    
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d", &x);
    
        if (x % p && f < 0) f = i; 
    }
    
    for (int i = 0 ; i < m ; ++ i) {
        int x;
        scanf("%d", &x);
        
        if (x % p && g < 0) g = i;
    }
    
    printf("%d", f + g);
    
}