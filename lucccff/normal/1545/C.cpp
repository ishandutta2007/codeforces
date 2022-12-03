#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,f,s,x,y;
    long long a[1050][550],p[1050],b[550],d[1050][1050],c[550];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<2*n;j++) {
            p[j]=0;
            for(k=0;k<n;k++) {
                cin>>a[j][k];
            }
        }
        memset(d,0,sizeof(d));

        for(j=0;j<2*n;j++) {
            for(k=j+1;k<2*n;k++) {
                f=0;
                for(l=0;l<n;l++) {
                    if (a[j][l]==a[k][l]) {
                        f=1;
                        break;
                    }
                }
                if (f) {
                    d[j][k]=d[k][j]=1;
                }
            }
        }

        s=1;
        for(j=0;j<n;j++) {
            for(l=0;l<n;l++) {
                memset(b,0,sizeof(b));
                for(k=0;k<2*n;k++) {
                    if (p[k]==0) {
                        b[a[k][l]]++;
                    }
                }
                for(k=1;k<=n;k++) {
                    if (b[k]==1) {
                        break;
                    }
                }
                if (k<=n) {
                    for(x=0;x<2*n;x++) {
                        if (a[x][l]==k&&p[x]==0) break;
                    }
                    c[j]=x+1;
                    p[x]=1;
                    for(y=0;y<2*n;y++) {
                        if (d[x][y]==1) p[y]=1;
                    }
                    break;
                }
            }
            if (l==n) {
                s=(s<<1)%MOD;
                x=0;
                while(p[x]==1) x++;
                c[j]=x+1;
                p[x]=1;
                for(y=0;y<2*n;y++) {
                    if (d[x][y]==1) p[y]=1;
                }
            }
        }
        cout<<s<<endl;
        for(j=0;j<n;j++) {
            cout<<c[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}