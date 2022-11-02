#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#define For(i,n) for(i=0;i<(n);i++)

int chk[105],cards[105];


void solve(int n){
    int i,j,p,m=10,t,x;
    char c[10];
    bool g=true;
    For(i,n){
        cards[i]=0;
        scanf("%s",&c);
        switch(c[0]){
        case 'R':
            cards[i]+=(1<<5);
            break;
        case 'G':
            cards[i]+=(1<<6);
            break;
        case 'B':
            cards[i]+=(1<<7);
            break;
        case 'Y':
            cards[i]+=(1<<8);
            break;
        case 'W':
            cards[i]+=(1<<9);
            break;
        }
        cards[i]+=(1<<(c[1]-'1'));
        chk[i]=0;
    }
    For(p,1<<10){
        g=true;
        x=p;
        t=0;
        while(x>0){
            if(x%2==1) t++;
            x/=2;
        }
        For(i,n){
            chk[i]=p&cards[i];
        }
        For(i,n-1){
            for(j=i+1;j<n;j++){
                if(cards[i]!=cards[j]&&chk[i]==chk[j]) g=false;
            }
        }
        if(g&&t<m) m=t;
    }
    printf("%d",m);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}