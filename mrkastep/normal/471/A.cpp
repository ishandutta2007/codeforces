#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int a[7],t,p,i;
    a[0]=n;
    a[6]=-1;
    For(i,5) scanf("%d",&a[i+1]);
    std::sort(a,a+6);
    t=1;
    i=1;
    while(a[i]==a[i-1]&&i<6){
        t++;
        i++;
    }
    i++;
    p=1;
    while(a[i]==a[i-1]&&i<6){
        p++;
        i++;
    }
    if(t==4&&p==2||t==6||t==2&&p==4){
        printf("Elephant");
        return;
    }
    if(t==4&&p==1||t==1&&p==4||t==5||p==5){
        printf("Bear");
        return;
    }
    if(t==1&&p==1){
        t=1;
        for(i=3;i<6;i++){
            if(a[i]==a[i-1]) t++;
        }
        if(t==4){
            printf("Bear");
            return;
        }
    }
    printf("Alien");
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