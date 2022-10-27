#include<bits/stdc++.h>
using namespace std;
const int maxn=2510;
long long bit[maxn][maxn];
int a[maxn][maxn];
void update(int x,int y,int val){
    for(int i=x;i<maxn;i+=(i&-(i)))
        for(int j=y;j<maxn;j+=(j&(-j)))
        bit[i][j]+=val;
    return;
}
long long get(int x,int y){
    long long res=0LL;
    for(int i=x;i>0;i-=(i&(-i)))
        for(int j=y;j>0;j-=(j&(-j)))
        res+=bit[i][j];
    return res;
}
int q,n,m;
///Thanks to TOI13 Art! :D

int main(){
    srand(time(0));
    scanf("%d%d%d",&n,&m,&q);
    int x,y,u,v,t;
    while(q--){
        scanf("%d%d%d%d%d",&t,&x,&y,&u,&v);
        if(t==1){
            a[x][y]=1LL*rand()*rand()+rand();
            int cur=a[x][y];
            update(x,y,cur);
            update(x,v+1,-cur);
            update(u+1,y,-cur);
            update(u+1,v+1,cur);
            ++cur;
        }
        else if(t==2){
            int res=a[x][y];
            update(x,y,-res);
            update(x,v+1,res);
            update(u+1,y,res);
            update(u+1,v+1,-res);
        }
        else if(t==3){
            printf((get(x,y)==get(u,v))?"Yes\n":"No\n");
        }
    }
}