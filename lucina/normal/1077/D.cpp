#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,a[maxn],c[maxn],d[maxn],p;
bool ss(int x){
    p=0;
    for(int i=1;i<=(int)2e5+10;i++){
        if(c[i])
        for(int j=1;j<=c[i]/x;j++){
            d[++p]=i;
        }
    }
    return p>=k;

}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
    int l=1,r=n+1,mi,ans=0;
    while(l<=r){
        mi=(l+r)/2;
        if(ss(mi)){
            ans=mi;
            l=mi+1;
        }
        else{
            r=mi-1;
        }
    }
    ss(ans);
    for(int i=1;i<=k;i++){
        printf("%d ",d[i]);
    }



}