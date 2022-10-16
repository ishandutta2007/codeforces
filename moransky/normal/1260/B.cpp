#include <cstdio>
#include <iostream>
using namespace std;
int a, b;
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &a, &b);
        if(a == b) {
            if(a % 3 == 0) puts("YES");
            else puts("NO");
            continue;
        }
        if(a > b) swap(a, b);
        int c = b - a;
        if(a < c) puts("NO");
        else {
            a -= c;
            if(a % 3 == 0) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}