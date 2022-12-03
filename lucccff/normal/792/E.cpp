#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[510];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    LL ans=1e10,s;
    for(i=1;i<4e4;i++) {
        int flag=1;
        s=0;
        for(j=0;j<n;j++) {
            k=a[j]/i;
            if (a[j]%i>k) {
                flag=0;
                break;
            }
            s+=(a[j]+i)/(i+1);
        }
        if (!flag) continue;
        ans=min(ans,s);
    }
    l=i;
    for(i=a[n-1]/i;i>=1;i--) {
        int i1=a[n-1]/i;
        int flag=1;
        s=0;
        for(j=0;j<n;j++) {
            k=a[j]/i1;
            if (a[j]%i1>k) {
                flag=0;
                break;
            }
            s+=(a[j]+i1)/(i1+1);
        }
        if (!flag) continue;
        ans=min(ans,s);
    }
    for(i=a[n-1]/l;i>=1;i--) {
        int i1=a[n-1]/i-1;
        if (i1==0) continue;
        int flag=1;
        s=0;
        for(j=0;j<n;j++) {
            k=a[j]/i1;
            if (a[j]%i1>k) {
                flag=0;
                break;
            }
            s+=(a[j]+i1)/(i1+1);
        }
        if (!flag) continue;
        ans=min(ans,s);
    }
    cout<<ans<<endl;
    return 0;
}