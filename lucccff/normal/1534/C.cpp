#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,ans;
    int a[400010],b[400010],c[400010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        for(j=0;j<n;j++) {
            cin>>b[j];
        }
        for(j=0;j<n;j++) {
            c[a[j]]=b[j];
        }
        for(j=0;j<n;j++) {
            a[j+1]=0;
        }
        m=0;
        for(j=1;j<=n;j++) {
            if (a[j]==0) {
                m++;
                a[j]=m;
                k=j;
                j=c[j];
                while(j!=k) {
                    a[j]=m;
                    j=c[j];
                }
            }
        }
        ans=1;
        for(j=0;j<m;j++) {
            ans=(ans*2)%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}