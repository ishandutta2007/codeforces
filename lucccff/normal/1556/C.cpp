#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,ans=0,y;
    long long a[1010],b[1010];
    cin>>n;
    b[0]=0;
    for(j=0;j<n;j++) {
        cin>>a[j];
        b[j+1]=b[j]+a[j]-a[j]*(j&1)*2;
    }
    for(j=0;j<n;j+=2) {
        y=a[j];
        for(k=j+1;k<n;k+=2) {
            l=b[k]-b[j+1]+a[j]-y;
            ans+=max(0ll,min(y,a[k]-l)+1);
            if (k==j+1)ans--;
            y=min(y,b[k+1]-b[j]);
            if (y<0) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}