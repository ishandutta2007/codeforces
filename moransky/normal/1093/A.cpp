#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        int x; scanf("%d", &x);
        printf("%d\n", x % 6 ? x / 6 + 1 : x / 6);
    }

    return 0;
}