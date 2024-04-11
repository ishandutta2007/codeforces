#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[2000][2000],b[2010];
    cin>>n;
    for(i=0;i<n;i++) cin>>b[i];
    sort(b,b+n);
    a[0][n-1]=0;
    for(i=1;i<n;i++) {
        for(j=0;j<=i;j++) {
            m=10000000000000;
            if (j>0) {
                if (a[j-1][n-i-1+j]+b[n-i-1+j]-b[j-1]<m) {
                    m=a[j-1][n-i-1+j]+b[n-i-1+j]-b[j-1];
                }
            }
            if (j<i) {
                if (a[j][n-i+j]+b[n-i+j]-b[j]<m) {
                    m=a[j][n-i+j]+b[n-i+j]-b[j];
                }
            }
            a[j][n-i-1+j]=m;
        }
    }
    m=10000000000000;
    for(i=0;i<n;i++) if (a[i][i]<m) m=a[i][i];
    cout<<m;
    return 0;
}