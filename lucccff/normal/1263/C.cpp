#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        k=sqrt(n);
        if (n/(k+1)==k) {
            cout<<2*k+1<<endl;
        }
        else {
            cout<<2*k<<endl;
        }
        for(j=0;j<=k;j++) {
            cout<<j<<' ';
        }
        if (n/(k+1)==k) j=k;
        else j=k-1;
        for(;j>=1;j--) {
            cout<<n/j<<' ';
        }
        cout<<endl;
    }
    return 0;
}