#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,q;
    long long p[200010],c[200010],a[200010],d[200010],ans[200010],b[200010];
    cin>>t;
    for(long long x=0;x<t;x++) {
        cin>>n;
        for(i=1;i<=n;i++) {
            cin>>p[i];
            b[i]=0;
            ans[i]=0;
        }
        for(i=1;i<=n;i++) {
            cin>>c[i];
        }
        for(i=1;i<=n;i++) {
            if (!b[i]) {
                b[i]=1;
                d[0]=i;
                m=1;
                k=p[i];
                while(k!=i) {
                    b[k]=1;
                    d[m++]=k;
                    k=p[k];
                }
                for(j=1;j*j<=m;j++) {
                    if (m%j==0) {
                        for(k=0;k<j;k++) {
                            a[k]=1;
                        }
                        for(k=0;k<m;k++) {
                            if (c[d[k]]!=c[d[(k+j)%m]]) a[k%j]=0;
                        }
                        for(k=0;k<j;k++) {
                            if (a[k]!=0) break;
                        }
                        if (k!=j) break;
                    }
                }
                if (j*j<=m) ans[j]=1;
                else {
                    for(j=m/j;j>=1;j--) {
                        if (m%j==0) {
                            for(k=0;k<m/j;k++) {
                                a[k]=1;
                            }
                            for(k=0;k<m;k++) {
                                if (c[d[k]]!=c[d[(k+m/j)%m]]) a[k%(m/j)]=0;
                            }
                            for(k=0;k<m/j;k++) {
                                if (a[k]!=0) break;
                            }
                            if (k!=m/j) break;
                        }
                    }
                    if (j>m/j) j=1;
                    ans[m/j]=1;
                }
            }
        }
        for(i=1;i<=n;i++) {
            if (ans[i]) {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}