#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,s,r,p,q;
    int a[101][101],b[101][101];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>m;
        for(j=0;j<n;j++) {
            for(k=0;k<m;k++) {
                cin>>a[j][k];
            }
        }
        memset(b,0,sizeof(b));
        for(j=0;j<m;j++) {
            s=1000000007;
            for(k=0;k<n;k++) {
                for(l=0;l<m;l++) {
                    if ((a[k][l]<s)&&(b[k][l]==0)) {
                        s=a[k][l];
                        p=k;
                        q=l;
                    }
                }
            }
            b[p][j]=j+1;
            if (q!=j) {
                a[p][q]+=a[p][j];
                a[p][j]=a[p][q]-a[p][j];
                a[p][q]-=a[p][j];
            }
        }
        for(j=0;j<n;j++) {
            for(k=0;k<m;k++) {
                cout<<a[j][k]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}