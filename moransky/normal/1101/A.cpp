#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        int l, r, d; scanf("%d%d%d", &l, &r, &d);
        if(d < l) printf("%d\n", d);
        else printf("%d\n", d * (r / d + 1));
    }
    return 0;
}