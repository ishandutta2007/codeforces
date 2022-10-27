#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,inf=1e9,M=1000000;
const int S= M<<2;
int sg[S],tg[S];
void push(int v){
    if(tg[v]!=0 && v*2+1 < S){ // check if leaf is not going out of bound
    sg[v*2] += tg[v];
    sg[v*2+1]+= tg[v];
    tg[v*2] +=tg[v];
    tg[v*2+1]+=tg[v];
    }
    tg[v] =0;
    return;
}
void update(int v,int x,int y,int l,int r,int val){
    if(l>r)return;
    push(v);
    if(l==x && r==y){
       tg[v]+=val,sg[v]+=val;
       return ;
    }
    push(v);
    int mid = x+y>>1;
    update(v*2,x,mid,l,min(r,mid),val);
    update(v*2+1,mid+1,y,max(l,mid+1),r,val);
    return (void)(sg[v] = max(sg[v*2],sg[v*2+1]));
}
int go(int v,int l,int r){
    push(v);
    if(l==r){
        return l;
    }
    int mid= l+r>>1;
    sg[v*2+1] > 0 ? go(v*2+1,mid+1,r): go(v*2,l,mid);
}
int n,m,q,a[maxn],b[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        update(1,1,M,1,a[i],1);
    }
    for(int i=1 ;i<=m; i++){
        scanf("%d", &b[i]);
        update(1,1,M,1,b[i],-1);
    }
    int t,x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&t,&x,&y);
        if(t == 1){
            update(1,1,M,1,a[x],-1);
            update(1,1,M,1,y,1);
            a[x] =y;
        }
        else{
            update(1,1,M,1,b[x],1);
            update(1,1,M,1,y,-1);
           // assert(y!=-1);
            b[x] =y;
        }
       push(1);
       //fprintf(stderr,"sg[1] = %d\n",sg[1]);
        if(sg[1]<=0){
            printf("-1\n");
        }
        else{
            printf("%d\n",go(1,1,M));
        }
    }

}
/**
4 6
1 8 2 4
3 3 6 1 5 2
3
1 1 1
2 5 10
1 1 6

1 2   4    8
1   3   5 6  10

**/