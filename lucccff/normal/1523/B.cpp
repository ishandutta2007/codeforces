#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) cin>>k;
        cout<<3*n<<endl;
        for(j=1;j<=n/2;j++) {
            cout<<1<<' '<<j<<' '<<n+1-j<<endl;
            cout<<2<<' '<<j<<' '<<n+1-j<<endl;
            cout<<1<<' '<<j<<' '<<n+1-j<<endl;
            cout<<2<<' '<<j<<' '<<n+1-j<<endl;
            cout<<1<<' '<<j<<' '<<n+1-j<<endl;
            cout<<2<<' '<<j<<' '<<n+1-j<<endl;
        }
    }
    return 0;
}