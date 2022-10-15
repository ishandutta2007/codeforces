#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,aa[3],bb[3],wa,wb;
vector<int> boba;
int nom(int a,int b,int &x,int &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    int z=nom(b,a%b,y,x);
    y-=a/b*x;
    return z;
}
int eat(){
    int ans=0,wo=1;
    for(int i=1;i<3;i++){
        int x,y,g=nom(wo,bb[i],x,y),qwq=(aa[i]-ans%bb[i]+bb[i])%bb[i];
        if(qwq%g)return -1;
        int z=bb[i]/g;
        ((x*=qwq)/=g)%=z;
        ans+=x*wo;
        wo*=z;
    }
    ((ans%=wo)+=wo)%=wo;
    if(!ans)ans+=wo;
    return ans;
}
bool wuwuwu(int x){
    int qq=(x/wa)*wb+(x%wa)-(upper_bound(boba.begin(),boba.end(),x%wa)-boba.begin());
    return qq>=k;
}
signed main(){
    cin>>n>>m>>k;
    int a[n+1],b[m+1],pos[max(n,m)*2+1]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(pos[b[i]]){
            int x=pos[b[i]],y=i;
            aa[1]=x;
            aa[2]=y;
            bb[1]=n;
            bb[2]=m;
            int zz=eat();
            if(zz!=-1)boba.push_back(zz);
        }
    }
    sort(boba.begin(),boba.end());
    wa=n/gcd(n,m)*m;
    wb=wa-boba.size();
    int l=1,r=1e18,ans=1e18;
    while(l<=r){
        int mid=(l+r)>>1;
        if(wuwuwu(mid)){
            if(mid==73)return 1;
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<"\n";
}