#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[101];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        l=1e9;
        for(j=0;j<n;j++) {
            cin>>a[j];
            if (a[j]<l) l=a[j];
        }
        k=0;
        for(j=0;j<n;j++) {
            if (a[j]==l) k++;
        }
        cout<<n-k<<endl;
    }
    return 0;
}