#include<bits/stdc++.h>
using namespace std;
const int block=705,maxn=5e5+1;
int f[block][block],a[maxn];
int get(int x,int y){
    int sum=0;
    for(int i=y;i<maxn;i+=x){
        sum+=a[i];
    }
    return sum;
}
void upd(int x,int y){
    //increase a[x] by y
    // f[x][y] = the answer for query x,y
    a[x]+=y;
    for(int i=1;i<=700;i++){
        f[i][x%i]+=y;
    }
}
 
int main(){
    int q,t,x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&t,&x,&y);
        if(t==1){
            upd(x,y);
        }
        else{
            if(x>=700){
                printf("%d\n",get(x,y));
            }
            else{
                printf("%d\n",f[x][y]);
            }
        }
    }
}
/*
    Good Luck
        -Lucina
*/