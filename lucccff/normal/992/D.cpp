#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[200010],b[200010],c[200010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    LL s,p,q,ans=0;
    cin>>n>>k;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    m=0;
    for(i=0;i<n;i++) {
        j=i+1;
        b[m]=a[i];
        while(j<n&&a[j]==1) j++;
        c[m]=j-i;
        i=j-1;
        m++;
    }
    if (k==1) ans+=n-m;
    for(i=0;i<m;i++) {
        s=1;
        p=0;
        if (i>0) q=c[i-1]-1;
        else q=0;
        for(j=1;j<=min(m-i,40);j++) {
            if (s/k>2e13/b[i+j-1]) break;
            s*=b[i+j-1];
            p+=b[i+j-1];
            //if (s/k>p+c[i+j-1]-1+q) break;
            if (s/k>=p&&s/k<=p+c[i+j-1]-1+q) {
                if (s%k==0) {
                    int x=c[i+j-1]-1,y=q,z=s/k-p;
                    if (x>y) swap(x,y);
                    if (z>y) {
                        ans+=x+y-z+1;
                    }
                    else if (z>x) {
                        ans+=x+1;
                    }
                    else {
                        ans+=z+1;
                    }
                }
            }
            p+=c[i+j-1]-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}