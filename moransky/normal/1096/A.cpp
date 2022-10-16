#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        int l, r; scanf("%d%d", &l, &r);
        printf("%d %d\n", l, l * 2);
    }
    return 0;
}