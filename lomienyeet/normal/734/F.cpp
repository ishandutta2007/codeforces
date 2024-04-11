#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int a[n+1]={},b[n+1],c[n+1],s=0,z=n<<1;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        s+=b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        s+=c[i];
    }
    if(s%z){
        cout<<"-1\n";
        return 0;
    }
    s/=z;
    for(int i=1;i<=n;i++){
        int aa=b[i]+c[i]-s;
        if(aa<0||aa%n){
            cout<<"-1\n";
            return 0;
        }
        a[i]=aa/n;
    }
    int d[n+1]={},e[n+1]={};
    for(int i=0;i<31;i++){
        int wa=0;
        for(int j=1;j<=n;j++){
            if(a[j]&(1ll<<i)){
                wa++;
                e[j]+=n*(1ll<<i);
            }
        }
        for(int j=1;j<=n;j++){
            if(a[j]&(1ll<<i))d[j]+=wa*(1ll<<i);
            else e[j]+=wa*(1ll<<i);
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=d[i]||c[i]!=e[i]){
            cout<<"-1\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}