#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#define For(i,n) for(i=0;i<(n);i++)

long long int max(long long int x,long long int y){
    return x>y?x:y;
}

void solve(int n){
    int i,t=0;
    if(n<4){
        printf("NO");
        return;
    }
    if(n%2==0){
        printf("YES\n");
        printf("1 * 2 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
        for(i=5;i<n;i+=2){
            printf("%d - %d = 1\n",i+1,i);
            t++;
        }
        For(i,t){
            printf("24 * 1 = 24\n");
        }
    }
    if(n%2==1){
        printf("YES\n");
        printf("4 * 5 = 20\n");
        printf("20 + 3 = 23\n");
        printf("23 + 2 = 25\n");
        printf("25 - 1 = 24\n");
        for(i=6;i<n;i+=2){
            printf("%d - %d = 1\n",i+1,i);
            t++;
        }
        For(i,t){
            printf("24 * 1 = 24\n");
        }
    }
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}