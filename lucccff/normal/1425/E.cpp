#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

long long a[100010],b[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y,ans;
    cin>>n>>k;
    m=0;
    for(i=0;i<n;i++) {
        cin>>a[i];
        m+=a[i];
    }
    for(i=0;i<n;i++) {
        cin>>b[i];
    }
    if (k==0) {
        ans=1e-9;
        l=m;
        for(i=0;i<n;i++) {
            if (l-b[i]>ans) ans=l-b[i];
            l-=a[i];
        }
        cout<<max(0ll,ans);
    }
    else if (k==1) {
        ans=1e9;
        for(i=0;i<n-1;i++) {
            if (b[i]<ans) {
                ans=b[i];
                x=i;
            }
        }
        ans=m-a[n-1]-ans;
        y=1e9;
        for(i=0;i<n;i++) {
            if (b[i]<y&&i!=x) {
                y=b[i];
            }
        }
        if (ans<ans-y+a[n-1]) ans=ans-y+a[n-1];
        l=m-a[0];
        for(i=1;i<n;i++) {
            if (l-b[i]>ans) ans=l-b[i];
            l-=a[i];
        }
        y=1e9;
        for(i=0;i<n;i++) {
            if (a[i]<y) {
                y=a[i];
            }
        }
        if (ans<m-y-b[0]) ans=m-y-b[0];
        cout<<max(0ll,ans);
    }
    else {
        ans=1e9;
        for(i=0;i<n-1;i++) {
            if (b[i]<ans) ans=b[i];
        }
        ans=m-ans;
        if (a[n-1]-b[n-1]>ans) ans=a[n-1]-b[n-1];
        cout<<max(0ll,ans);
    }
    return 0;
}