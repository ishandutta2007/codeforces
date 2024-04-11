#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],b[maxn],c[maxn],d[maxn],n,bit[maxn],x;
int get(int idx){
    int sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

void update(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=(idx)&(-idx);
    }
    return ;
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        d[b[i]]++;
    }
    for(int i=0;i<n;i++){
        if(d[i]){
            update(i+1,1);
        }
    }    for(int i=1;i<=n;i++){
            int id=((n-a[i])%n)+1;
        x=get(id-1);
        int l=id,r=n,mid,ans=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(get(mid)>x){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==-1){
                l=1,r=id-1;
            while(l<=r){
                mid=(l+r)>>1;
                if(get(mid)>0){
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        d[ans-1]--;
        if(d[ans-1]==0)
            update(ans,-1);
        c[i]=(a[i]+(ans-1))%n;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",c[i]);



}