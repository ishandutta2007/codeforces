#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[300010],b[300010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,p;
    LL ans=0;
    cin>>n>>p>>k;
    for(i=0;i<n;i++) {
        cin>>a[i];
        l=1ll*a[i]*a[i]%p;
        b[i]=1ll*l*l%p;
        b[i]=(b[i]+p-1ll*k*a[i]%p)%p;
    }
    sort(b,b+n);
    for(i=0;i<n;i++) {
        j=i+1;
        while(j<n&&b[j]==b[j-1]) j++;
        ans+=1ll*(j-i)*(j-i-1)/2;
        i=j-1;
    }
    cout<<ans<<endl;
    return 0;
}