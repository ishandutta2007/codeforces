#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    if(n==1 || n==2) {
        printf("1");
        return 0;
    }
    int x=4;
    int px=1;
    while(x<=n) {
        if(x==n || x+1==n) {
            printf("1");
            return 0;
        }
        int t = x;
        if(px % 2 == 1) x = 2 * x + 1;
        else x = 2 * x + 2;
        px = t;
    }
    printf("0");
    return 0;
}