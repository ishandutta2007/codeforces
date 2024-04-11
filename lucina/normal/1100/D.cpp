#include<bits/stdc++.h>
using namespace std;
int x,y,c[1005][1005],u,v,w,dx,dy,dp[1010][1010],fuck;
struct rook{
    int L,R;
}r[700];
void query(int a,int b){
    printf("%d %d\n",a,b);
    fflush(stdout);
    x=a,y=b;
    return;
}
void change(){
    scanf("%d%d%d",&u,&v,&w);
    if(u<=0)exit(0);
    c[r[u].L][r[u].R]=0;
    r[u].L=v,r[u].R=w;
    c[v][w]=1;
    return;
}
void movee(){
    if(x<500){
        query(x+1,y);
        return;
    }
    else if(x>500){
        query(x-1,y);
        fflush(stdout);
        return;
    }
    else if(y<500){
        query(x,y+1);
        fflush(stdout);
        return;
    }
    else if(y>500){
        query(x,y-1);
        fflush(stdout);
        return;
    }
}
void fast(){
    if(c[x+dx][y+dy]){
        query(x+dx,y);
    }
    else{
        query(x+dx,y+dy);
    }
    change();
    return;
}

int main(){
    scanf("%d%d",&x,&y);
    int reg=0;
    for(int i=1;i<=666;i++){
        scanf("%d%d",&r[i].L,&r[i].R);
        c[r[i].L][r[i].R]=1;
    }
    while(!(x==500&&y==500)){
        movee();
        change();
    }
    int d[5];
    int mi=16151621;
    memset(d,0,sizeof(d));
    for(int i=1;i<=999;i++)
    for(int j=1;j<=999;j++){
        if(c[i][j]){
            if(i<500&&j<500)d[1]++;
            if(i>500&&j<500)d[2]++;
            if(i<500&&j>500)d[3]++;
            if(i>500&&j>500)d[4]++;
        }
    }
    for(int i=1;i<=4;i++){
        if(d[i]<mi){
            mi=d[i];
            reg=i;
        }
    }
    if(reg==1)dx=1,dy=1;
    else if(reg==2)dx=-1,dy=1;
    else if(reg==3)dx=1,dy=-1;
    else dx=-1,dy=-1;
    //if(shit)reg=1;
    int ct=0;
    while(true){
        fast();
    }

}