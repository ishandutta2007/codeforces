#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[400010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        if (n==1) {
            cout<<a[0]<<endl;
            continue;
        }
        k=a[0]+a[n-1];
        for(j=0;j<n-1;j++) {
            k+=abs(a[j]-a[j+1]);
        }
        if (a[0]>a[1]) k-=a[0]-a[1];
        if (a[n-1]>a[n-2]) k-=a[n-1]-a[n-2];
        for(j=1;j<n-1;j++) {
            if (a[j]>a[j-1]&&a[j]>a[j+1]) {
                k-=a[j]-max(a[j-1],a[j+1]);
            }
        }
        cout<<k<<endl;
    }
    return 0;
}