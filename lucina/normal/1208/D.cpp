#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long bit[maxn];
long long get(int idx){
    long long sum=0;
    while(idx>0){
        sum+=(bit[idx]);
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(int idx,int val){
    while(idx<=200001){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
    return;
}
int n,a[maxn];
long long s[maxn];
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        update(i,i);
    }
    for(int i=n;i>=1;i--){
        int l=1,r=n,mid,ans=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(get(mid)>s[i]){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        a[i]=ans;
        update(a[i],-a[i]);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
}
/*
    Good Luck
        -Lucina
*/