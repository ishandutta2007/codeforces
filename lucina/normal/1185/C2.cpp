#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,d;
struct{
int bit[102];
int get(int idx){
    int sum=0;
    while(idx>0){
        sum+=(bit[idx]);
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(int idx,int val){
    while(idx<=100){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
    return;
}
pair<int,int> lifting(int val){
    int sum=0,pos=0;
    for(int i=7;i>=0;i--){
        if(pos+(1<<i)<=100&&sum+bit[pos+(1<<i)]<val){
            pos+=(1<<i);
            sum+=bit[pos];
        }
    }
    return make_pair(pos+1,sum);
}
}f1,f2;
int main(){
    scanf("%d%d",&n,&m);
    int x,c;
    for(int i=1;i<=n;i++){
        scanf("%d",&d);
        auto it=f1.lifting(m-d);
        int pos=it.first;
        int g1=f2.get(pos),g2=f2.get(pos-1);
        x=g1-g2;
        c=g2;
        c+=(min(x,(m-d-(it.second))/pos));
        printf("%d ",i-c-1);
        f1.update(d,d);
        f2.update(d,1);
    }
}
/*
    Good Luck
         -Lucina
*/