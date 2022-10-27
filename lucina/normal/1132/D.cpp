#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k;
long long a[maxn],b[maxn],ans,l,r,mid,d[maxn],c[maxn];
bool ch(long long x){
    for(int i=1;i<=k;i++)c[i]=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        long long g=a[i];
        while(g<b[i]*(k-1)){
            c[g/b[i]+1]++;
            cnt++;if(cnt>k)return false;
            g+=x;
        }
    }
    for(int i=1;i<=k;i++){
        c[i]+=c[i-1];
        if(c[i]>i)return false;
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    l=0ll,r=(long long)2e12,ans=-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(ch(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        }
    printf("%lld\n",ans);

}