#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

const int P=16;

int a[410][410],b[410][410],c[410][410],d[410][410];

int main() {
    int i,j,k,l,m,n,t,x,y,mi;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(i=0;i<n;i++) {
            getchar();
            for(j=0;j<m;j++) {
                if (getchar()=='0') {
                    a[i][j]=0;
                }
                else {
                    a[i][j]=1;
                }
            }
        }
        c[0][0]=d[0][0]=b[0][0]=a[0][0];
        for(i=1;i<n;i++) {
            c[i][0]=a[i][0];
            d[i][0]=d[i-1][0]+a[i][0];
            b[i][0]=b[i-1][0]+a[i][0];
        }
        for(i=1;i<m;i++) {
            d[0][i]=a[0][i];
            c[0][i]=c[0][i-1]+a[0][i];
            b[0][i]=b[0][i-1]+a[0][i];
        }
        for(i=1;i<n;i++) {
            for(j=1;j<m;j++) {
                d[i][j]=d[i-1][j]+a[i][j];
                c[i][j]=c[i][j-1]+a[i][j];
                b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
            }
        }
        mi=16;
        for(i=0;i<=n-5;i++) {
            for(j=0;j<=m-4;j++) {
                for(k=5;k+i<=n;k++) {
                    if (k-2-d[i+k-2][j]+d[i][j]>16) break;
                }
                x=k;
                for(k=4;k+j<=m;k++) {
                    if ((k-2-c[i][j+k-2]+c[i][j])>16) break;
                }
                y=k;
                for(k=5;k<x;k++) {
                    for(l=4;l<y;l++) {
                        if (b[i+k-2][j+l-2]-b[i+k-2][j]-b[i][j+l-2]+b[i][j]+k+2*l-6-c[i][j+l-2]+c[i][j]-d[i+k-2][j]+d[i][j]-c[i+k-1][j+l-2]+c[i+k-1][j]>16) break;
                        mi=min(mi,b[i+k-2][j+l-2]-b[i+k-2][j]-b[i][j+l-2]+b[i][j]+2*k+2*l-8-d[i+k-2][j]+d[i][j]-c[i][j+l-2]+c[i][j]-d[i+k-2][j+l-1]+d[i][j+l-1]-c[i+k-1][j+l-2]+c[i+k-1][j]);
                    }
                }
            }
        }
        cout<<mi<<endl;
    }
    return 0;
}