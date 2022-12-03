#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        if (n%2==1) {
            cout<<"NO\n";
            continue;
        }
        l=sqrt(n);
        k=sqrt(2*n);
        if ((l*l==n)||(k*k==2*n)) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}