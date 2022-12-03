#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n;
    long long a[200010],b[200010],c[200010];
    cin>>n>>m;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<m;i++) {
        b[i]=a[i];
    }
    for(i=m;i<n;i++) {
        b[i]=a[i]+b[i-m];
    }
    c[0]=a[0];
    for(i=1;i<n;i++) {
        c[i]=c[i-1]+b[i];
    }
    for(i=0;i<n;i++) {
        cout<<c[i]<<' ';
    }
    return 0;
}