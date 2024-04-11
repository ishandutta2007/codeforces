#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        m=n-k+k/2;
        cout<<m<<endl;
        for(j=k+1;j<=n;j++) cout<<j<<' ';
        for(j=1;j*2<=k;j++) cout<<k-j<<' ';
        cout<<endl;
    }
    return 0;
}