#include <stdio.h>

int yy[]={0,0,1,1},xx[]={0,1,0,1};
int N,M,S[503][503],ans;
char map[503][503];
bool V[503][503][9][16],V2[503][503][9][16];

int get_sum(int sy,int sx,int ey,int ex){ return S[ey][ex]-S[sy-1][ex]-S[ey][sx-1]+S[sy-1][sx-1]; }
bool all_black(int sy,int sx,int ey,int ex){ return get_sum(sy,sx,ey,ex) == (ey-sy+1)*(ex-sx+1); }
bool all_white(int sy,int sx,int ey,int ex){ return get_sum(sy,sx,ey,ex) == 0; }

bool is_fractal(int y,int x,int s,int p)
{
    if (V[y][x][s][p]) return V2[y][x][s][p];
    V[y][x][s][p] = 1;
    int i,arr[4]={0,},sy,sx,ey,ex;
    for (i=0;i<4;i++) arr[i] = (p>>i)&1;
    int size=(1<<(s-1));
    for (i=0;i<4;i++){
        sy = y+yy[i]*size;
        sx = x+xx[i]*size;
        ey = sy+size-1;
        ex = sx+size-1;
        if (arr[i] && !all_black(sy,sx,ey,ex)) break;
        if (!arr[i]){
            if (s == 1 && !all_white(sy,sx,ey,ex)) break;
            if (s > 1 && !is_fractal(sy,sx,s-1,p)) break;
        }
    }
    if (i < 4) return 0;
    V2[y][x][s][p] = 1;
    return 1;
}

int main()
{
    int i,j,k,v;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++){
        scanf("%s",map[i]+1);
        for (j=1;j<=M;j++){
            S[i][j] = (map[i][j]=='*');
            S[i][j] = S[i][j]+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
        }
    }
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        for (k=2;i+(1<<k)-1<=N&&j+(1<<k)-1<=M;k++){
            for (v=0;v<(1<<4);v++){
                if (is_fractal(i,j,k,v)){
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d",ans);
}