#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],m,ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    ans=-1;
    int l=1,r=n,mid,pt;
    long long ct,sum;
    while(l<=r){
     mid=(l+r)>>1;
     ct=0,sum=0;
     pt=0;
     for(int i=n;i>=1;i--){
        ct++;
        if(ct>mid){
            ct-=mid;
            pt++;
        }
        sum+=max(0,a[i]-pt);
     }
        if(sum>=m){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);

}