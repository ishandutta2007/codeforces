#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(j=0;j<t;j++){
        cin>>n>>k;
        if (k*2<=n-1) {
            cout<<1<<' ';
            for(i=1;i<=k;i++) {
                cout<<i*2+1<<' '<<i*2<<' ';
            }
            for(i=2*k+2;i<=n;i++) {
                cout<<i<<' ';
            }
            cout<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
    return 0;
}