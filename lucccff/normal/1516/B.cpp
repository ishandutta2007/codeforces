#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[2010],b[2010];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        b[0]=a[0];
        for(j=1;j<n;j++) b[j]=a[j]^b[j-1];
        if (b[n-1]==0) {
            cout<<"YES\n";
            continue;
        }
        k=n-1;
        while((k>0)&&(b[k]!=0)) k--;
        if (k==0) {
            cout<<"NO\n";
            continue;
        }
        int f=0;
        for(j=0;j<k;j++) if (b[j]==b[n-1]) {
            f=1;
            break;
        }
        if (f==1) {
            cout<<"YES\n";
            continue;
        }
        else {
            cout<<"NO\n";
            continue;
        }
    }
    return 0;
}