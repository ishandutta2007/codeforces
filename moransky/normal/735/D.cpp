#include <iostream>
#include <cstdio>
using namespace std;
int n;  
bool inline isPrime(int x){
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}
int main(){
    scanf("%d", &n);
    if(isPrime(n)) puts("1");
    else if((n & 1) == 0) puts("2");
    else if(isPrime(n - 2)) puts("2");
    else puts("3");
    return 0;
}