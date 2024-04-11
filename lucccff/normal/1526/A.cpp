#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    long long a[60],b[60];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<2*n;j++) {
            cin>>a[j];
        }
        sort(a,a+2*n);
        for(j=0;j<n;j++) {
            cout<<a[j]<<' '<<a[j+n]<<' ';
        }
        cout<<endl;
    }
    return 0;
}