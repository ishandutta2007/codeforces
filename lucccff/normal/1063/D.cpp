#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t,r,q,p,f=0;
    LL l1,r1;
    cin>>n>>l>>r>>k;
    q=(r-l+n)%n+1;
    /*l=0;
    r=n;
    while(l<r) {
        m=(l+r)/2;
        p=k%(m+n);
        l1=max(0,m-(n-q)-1)+q;
        r1=min(m,q)+q;
        if (p>=l1&&p<=r1) 
    }*/
    if (n<3e5) {
        for(j=n;j>=0;j--) {
            p=(k-1)%(n+j)+1;
            l1=max(0ll,j-(n-q)-1)+q;
            r1=min(j,q)+q;
            if (p>=l1&&p<=r1) break;
        }
        cout<<j<<endl;
    }
    else {
        for(i=k/(2*n);i<=k/n;i++) {
            if (i==0) {
                if (k>=q&&k<=2*q) {
                    f=1;
                    j=min(q,k-q+1)+n-q;
                    break;
                }
                else {
                    continue;
                }
            }
            p=(k-q)/i;
            r=(k-2*q-1)/i;
            if (p-n>n-q) {
                p=(k+2*(n-q)+1)/(i+1)+2;
            }
            for(j=p-n;j>max(-1ll,r-n);j--) {
                l=(k-1)%(n+j)+1;
                l1=max(0ll,j-(n-q)-1)+q;
                r1=min(j,q)+q;
                if (l>=l1&&l<=r1) {
                    f=1;
                    break;
                }
                else if (l>r1) break;
            }
            if (f) break;
        }
        if (f) {
            cout<<j<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
    return 0;
}