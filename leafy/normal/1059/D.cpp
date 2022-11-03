#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const int N=100005;
int n;
int x[N],y[N];
db l[N],r[N];
inline bool check(db R){
    for(int i=1;i<=n;i++){
        db tr=(2*R-y[i])*y[i];
        if(tr<0) return 0;
        tr=sqrt(tr);
        l[i]=x[i]-tr,r[i]=x[i]+tr;
    }
    db maxl=*max_element(l+1,l+n+1),minr=*min_element(r+1,r+n+1);
    if(maxl>minr) return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    int f1=0,f2=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        if(y[i]>0) f1=1;
        else f2=1;
    }
    if(f1&&f2){
        puts("-1");
        return 0;
    }
    if(f2) for(int i=1;i<=n;i++) y[i]=-y[i];
    db l=0,r=1e15,mid,ans=-1;
    for(int T=250;T;T--){
        mid=(l+r)*0.5;
        if(check(mid)) r=ans=mid;
        else l=mid;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(8) << ans;
    return 0;
}