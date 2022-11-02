#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>

#define For(i,n) for(i=0;i<(n);i++)
#define pb push_back

int a[3][3];

bool chk(int type){
    if(a[0][0]==type&&a[0][1]==type&&a[0][2]==type||a[1][0]==type&&a[1][1]==type&&a[1][2]==type||
        a[2][0]==type&&a[2][1]==type&&a[2][2]==type||a[0][0]==type&&a[1][0]==type&&a[2][0]==type||
        a[0][1]==type&&a[1][1]==type&&a[2][1]==type||a[0][2]==type&&a[1][2]==type&&a[2][2]==type||
        a[0][0]==type&&a[1][1]==type&&a[2][2]==type||a[0][2]==type&&a[1][1]==type&&a[2][0]==type){
            return true;
    }
    return false;
}

void solve(){
    int i,a1=0,a2=0;
    char x;
    For(i,9){
        scanf("%c",&x);
        switch(x){
        case 'X':
            a[i/3][i%3]=1;
            a1++;
            break;
        case '0':
            a[i/3][i%3]=2;
            a2++;
            break;
        case '.':
            a[i/3][i%3]=0;
            break;
        }
        if(i%3==2){
            getchar();
        }
    }
//  printf("%d %d\n",chk(1)?1:0,chk(2)?1:0);
    if(a1-a2>1||a1-a2<0||chk(2)&&a1!=a2||chk(1)&&a1==a2){
        printf("illegal");
        return;
    }
    if(chk(1)&&chk(2)){
        printf("illegal");
        return;
    }
    if(chk(1)){
        printf("the first player won");
        return;
    }
    if(chk(2)){
        printf("the second player won");
        return;
    }
    if(a1+a2==9){
        printf("draw");
        return;
    }
    if(a1>a2){
        printf("second");
        return;
    }
    else{
        printf("first");
        return;
    }

}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
//  while(scanf("%d",&n)!=EOF){
        solve();
//  }
    return 0;
}