#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;
bool is_prime(int u){
    for(int i=2;i*i<=u;i++) if(u % i == 0) return 0;
    return 1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        puts(n != 2 && (n == 1 || (n%2 == 0 && (__builtin_popcount(n) == 1 || is_prime(n/2))))?"FastestFinger":"Ashishgup");
    }
}