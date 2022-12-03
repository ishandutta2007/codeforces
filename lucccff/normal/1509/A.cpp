#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    int a[2010];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        for(j=0;j<n;j++) if (a[j]%2!=0) cout<<a[j]<<' ';
        for(j=0;j<n;j++) if (a[j]%2==0) cout<<a[j]<<' ';
        cout<<endl;
    }
    return 0;
}