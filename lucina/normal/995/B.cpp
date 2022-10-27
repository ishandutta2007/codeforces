#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[205];
int ans;
int bit[205];
int get(int idx){
    int sum=0;
    for(;idx>0;idx-=(idx&(-idx)))
        sum+=bit[idx];
    return sum;
}
void update(int idx,int val){
    for(;idx<=2*n;idx+=(idx&(-idx)))
        bit[idx]+=val;
    return;
}
int p[105];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        scanf("%d",&a[i]);
        p[a[i]]=i;
        update(i,1);
    }
    int cur;
    for(int i=1;i<=2*n;i++){
        if(p[a[i]]==0)continue;
        update(i,-1);
        cur=get(p[a[i]]);
        ans+=(cur-1);
        update(p[a[i]],-1);
        p[a[i]]=0;
    }
    printf("%d\n",ans);
}