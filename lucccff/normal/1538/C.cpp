#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i,j,k,l,m,n,t,r,ans;
    long long a[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>l>>r;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        sort(a,a+n);
        k=0;
        m=0;
        ans=0;
        for(j=n-1;j>=0;j--) {
            while(k<n&&a[k]+a[j]<l) k++;
            while(m<n&&a[m]+a[j]<=r) m++;
            ans+=m-k;
        }
        for(j=0;j<n-1;j++) {
            if (a[j]+a[j]>=l&&a[j]+a[j]<=r) ans--;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}