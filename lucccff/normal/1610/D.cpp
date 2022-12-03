#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

int a[200010],b[200010];

LL qp(LL n,LL m) {
    LL k=1,t=n;
    while(m) {
        if (m&1) k=k*t%MOD;
        t=t*t%MOD;
        m>>=1;
    }
    return k;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,flag=0;
    LL ans=0;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    m=0;
    flag=0;
    for(i=0;i<n;i++) {
        if (a[i]&1) flag=1;
        else {
            a[i]>>=1;
            if (a[i]) b[m++]=a[i];
        }
    }
    if (flag) {
        ans+=qp(2,n)+MOD-qp(2,m);
        ans%=MOD;
    }
    n=m;
    for(i=0;i<m;i++) a[i]=b[i];
    while(n) {
        m=0;
        flag=0;
        for(i=0;i<n;i++) {
            if (a[i]&1) flag=1;
            else {
                a[i]>>=1;
                if (a[i]) b[m++]=a[i];
            }
        }
        if (flag) {
            ans+=qp(2,n-1)+MOD-qp(2,m);
            ans%=MOD;
        }
        n=m;
        for(i=0;i<m;i++) a[i]=b[i];
    }
    cout<<ans;
    return 0;
}