#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,f;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        f=0;
        for(j=0;j<n;j++) {
            cin>>k;
            l=sqrt(k);
            if (l*l!=k) {
                f=1;
            }
        }
        if (f==0) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}