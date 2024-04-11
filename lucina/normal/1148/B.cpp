#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,ta,tb,a[maxn],b[maxn],k,s;

int main(){
    scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=ta;
        }
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    if(k>=n)return !printf("-1");
    int l,r,mid,ans=-1,ans1;
    for(int i=0;i<=k;i++){
        s=a[i+1];
        if(b[m]<s){
            return !printf("-1");
        }
        l=1,r=m,ans1=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(b[mid]>=s){
                ans1=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans1+(k-i)>m)return !printf("-1");
        ans=max(ans,b[ans1+(k-i)]+tb);
    }
    printf("%d\n",ans);
}