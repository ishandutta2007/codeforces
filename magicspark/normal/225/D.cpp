#include<stdio.h>
#include<stdlib.h>
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
char mp[20][20];
int bMap[20][20];
int isGo[20][20];
int Tx,Ty;
int Sx,Sy;
int n,m;
int L;
struct node{
    int map[20][20];
    int hx,hy;
    int move;
    bool canGo(int x,int y){
        if(isGo[x][y]>=20)return false;
        if(x<0||x>=n||y<0||y>=m)return false;
        if(mp[x][y]=='#')return false;
        if(mp[x][y]=='@')return true;
        if(map[x][y]+move>= L )return true;

        return false;
    }
    bool finish(){
        return hx==Tx&&hy==Ty;
    }
    void Go(int x,int y){
        map[x][y]=-move;
        isGo[x][y]++;
        move++;
        hx=x;
        hy=y;
    }
    void init(){
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)map[i][j]=bMap[i][j];
        hx=Sx;hy=Sy;
        move=0;
    }
};
node Q[50000];
int f=0,r=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",mp[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bMap[i][j]=1000;
            if(mp[i][j]=='@'){
                Tx=i;Ty=j;
            }
            if(mp[i][j]>='1'&&mp[i][j]<='9'){
                bMap[i][j]=mp[i][j]-'0';
                if(mp[i][j]-'0' >L)L= mp[i][j]-'0';
                if(mp[i][j]=='1'){
                    Sx=i;Sy=j;
                }
            }

        }
    }
    node t;
    t.init();
    Q[r++]=t;

    while(f<r){
        t=Q[f++];
        if(t.finish()){
            printf("%d\n",t.move);
            return 0;
        }
        for(int i=0;i<4;i++){
            if(t.canGo(t.hx+dx[i],t.hy+dy[i])){
                node nt=t;
                nt.Go( t.hx+dx[i],t.hy+dy[i]);
                Q[r++]=nt;
            }
        }
    }
    printf("-1\n");
    return 0;
}