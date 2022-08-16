#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
struct yqh{
    int x,y;
}fa[1020][1020];
int n,m,k;
int mp[1020][1020];
yqh getfa(int x,int y){
    if(fa[x][y].x == x && fa[x][y].y == y)return fa[x][y];
    fa[x][y] = getfa(fa[x][y].x,fa[x][y].y);
    return fa[x][y];
}
int get(){
    char t = getchar();
    while(t<'0' || t > '9') t=getchar();
    int x = 0;
    while(t>='0'&&t<='9'){
        x *= 10;
        x += t - '0';
        t = getchar();
    }
    return x;
}

int main(){
    n = get();
    m = get();
    k = get();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            mp[i][j] = get();
            if(mp[i][j] == 2){
                fa[i][j].x = i+1;
                fa[i][j].y = j;
            }else{
                fa[i][j].x = i;
                fa[i][j].y = j;
            }
        }
    }
    for(int j=1;j<=m;++j){
        fa[n+1][j].x = n+1;
        fa[n+1][j].y = j;
    }
    for(int i=1;i<=k;++i){
        int sx = 1;
        int sy = get();
        while(sx <= n){
            yqh nex = getfa(sx, sy);
            sx = nex.x;
            sy = nex.y;
            if(sx <= n){
                int flag = mp[sx][sy];
                mp[sx][sy] = 2;
                fa[sx][sy].x = sx+1;
                fa[sx][sy].y = sy;
                if(flag == 1) ++ sy;
                else if(flag == 2) ++ sx;
                else -- sy;
            }
        }
        printf("%d",sy);
        if(i<k)printf(" ");else printf("\n");
    }
    return 0;
}