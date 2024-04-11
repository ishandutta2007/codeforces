#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
char s[nax];
int n, a[4], cx, cy;
void solve(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i ++){
        if(s[i] == 'L') a[0] ++;
        else if(s[i] == 'R') a[1] ++;
        else if(s[i] == 'U') a[2] ++;
        else if(s[i] == 'D') a[3] ++;
        else throw;
    }
    cx = min(a[0], a[1]);
    cy = min(a[2], a[3]);
    if(cx == 0){
        if(cy > 0) printf("2\nUD\n");
        else printf("0\n");
        return ;
    }
    if(cy == 0){
        if(cx > 0) printf("2\nLR\n");
        else printf("0\n");
        return ;
    }
    cout << (cx + cy) * 2 << '\n';
    for(int i = 1 ;i <= cx ; i ++)
        printf("L");
    for(int i = 1 ;i <= cy; i ++ )
        printf("U");
    for(int i = 1 ;i <= cx ; i ++)
        printf("R");
    for(int i = 1 ;i <= cy ;i ++)
        printf("D");
    printf("\n");
}

int main(){
    int q;
    for(cin >> q ; q -- ; ){
        solve();
    }
}