#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,s;
    long long a[1010][1010];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        if (k==1) cout<<1<<endl;
        else if (n==1) cout<<2<<endl;
        else {
            for(j=1;j<=n;j++) {
                a[1][j]=1;
            }
            for(j=2;j<k;j++) {
                s=0;
                for(l=1;l<n;l++) {
                    s=(s+a[j-1][n-l])%MOD;
                    a[j][l]=s+1;
                }
            }
            s=2;
            for(j=1;j<n;j++) {
                s=(s+a[k-1][j])%MOD;
            }
            cout<<s<<endl;
        }
    }
    return 0;
}