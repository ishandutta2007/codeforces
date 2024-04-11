#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,f;
    long long a[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        cout<<n/2<<endl;
        for(j=0;j<n-1;j+=2) {
            k=min(a[j],a[j+1]);
            cout<<j+1<<' '<<j+2<<' '<<k<<' '<<1000000007<<endl;
        }
    }
    return 0;
}