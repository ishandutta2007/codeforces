#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef long double ld;

ld mm=0;

int xs[4];
int ys[4];

int mxs[4];
int mys[4];

int used[1001][1001];

ld di (int x1,int y1,int x2,int y2){
    return sqrt(abs((ld)x1-(ld)x2)*abs((ld)x1-(ld)x2)+abs((ld)y1-(ld)y2)*abs((ld)y1-(ld)y2));
}

int n,m;

void dfs (int x, int y, int d, ld ma){
    if (x<0||y<0) return;
    if (x>n||y>m) return;
    if (used[x][y]) return;
    used[x][y]=1;
    xs[d]=x;
    ys[d]=y;
    if (d==3){
        if (ma>mm){
            mm=ma;
            for (int i=0;i<4;i++){
                mxs[i]=xs[i];
                mys[i]=ys[i];
            }
        }
        used[x][y]=0;
        return;
    }
    for (int i=0;i<4;i++){
        for (int ii=0;ii<4;ii++){
            dfs(i,ii,d+1,ma+di(x,y,i,ii));
        }
    }
    for (int i=0;i<4;i++){
        for (int ii=0;ii<4;ii++){
            dfs(n-i,m-ii,d+1,ma+di(x,y,n-i,m-ii));
        }
    }
    used[x][y]=0;
}

int main(){
    cin>>n>>m;
    for (int i=0;i<4;i++){
        for (int ii=0;ii<4;ii++){
            dfs(i,ii,0,0);
        }
    }
    for (int i=0;i<4;i++){
        cout<<mxs[i]<<" "<<mys[i]<<endl;
    }
}