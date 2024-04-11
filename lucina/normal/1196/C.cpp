#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct rec{
    int x1,y1,x2,y2;
    rec(int _x1,int _y1,int _x2,int _y2):
        x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
    rec():
        x1(0),y1(0),x2(0),y2(0){}
    bool operator ==(const rec &a)const{
        return a.x1==x1&&a.x2==x2&&a.y1==y1&&a.y2==y2;
    }
    friend rec intersect(const rec &a,const rec &b){
        rec shit=rec(maxn,maxn,maxn,maxn);
        if(a==shit||b==shit)return shit;
        rec nw;
        nw.x1=max(a.x1,b.x1);
        nw.x2=min(a.x2,b.x2);
        if(nw.x1>nw.x2)return shit;
        nw.y1=min(a.y1,b.y1);
        nw.y2=max(a.y2,b.y2);
        if(nw.y1<nw.y2)return shit;
        return nw;
    }
}a;
struct pt{
    int x,y;
    void read(){
    scanf("%d%d",&x,&y);
    }
    pt():x(0), y(0){}
    pt(int _x,int _y): x(_x),y(_y){}
}p;
int n,q;
bool trash;
const int lim=100000;

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        rec ans=rec(-lim,lim,lim,-lim);
        for(int i=1;i<=n;i++){
            p.read();
            a=rec(p.x,p.y,p.x,p.y);
            /** 0 left
                1 up
                2 right
                3 down
            **/
            for(int i=0;i<4;i++){
                scanf("%1d",&trash);
                if(trash){
                    if(i==0){
                        a.x1=-lim;
                    }
                    else if(i==1){
                        a.y1=lim;
                    }
                    else if(i==2){
                        a.x2=lim;
                    }
                    else if(i==3){
                        a.y2=-lim;
                    }
                }
            }
            ans=intersect(ans,a);
        }
        if(ans.x1==maxn){
            printf("0\n");
            continue;
        }
        printf("1 %d %d\n",ans.x1,ans.y1);
    }
}
/*
    Good Luck
        -Lucina
*/