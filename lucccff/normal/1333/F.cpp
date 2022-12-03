#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,x;
    int p[500010],q[500010];
    cin>>n;
    memset(p,0,sizeof(p));
    memset(q,200000,sizeof(q));
    p[1]=0;
    for(j=2;j<=n;j++) {
        if (!p[j]) {
            p[1]++;
            p[j]=min(p[1],q[n/j]);
            for(i=j+j;i<=n;i+=j) {
                if (!p[i]) p[i]=p[j];
            }
        }
        else {
            if (p[j]>q[n/j]) p[j]=q[n/j];
        }
        q[j]=p[1];
    }
    m=0;
    for(j=1;j<=n;j++) {
        for(k=0;k<p[j];k++) {
            cout<<j<<' ';
            m++;
            if (m>=n-1) break;
        }
        if (m>=n-1) break;
    }
    return 0;
}