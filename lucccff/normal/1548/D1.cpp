#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,ans=0,x,y;
    long long a[4];
    cin>>n;
    memset(a,0,sizeof(a));
    for(j=0;j<n;j++) {
        cin>>x>>y;
        k=((x/2)&1)*2+((y/2)&1);
        a[k]++;
    }
    for(j=0;j<4;j++) {
        ans+=a[j]*(a[j]-1)/2*(n-a[j]);
        ans+=a[j]*(a[j]-1)*(a[j]-2)/6;
    }
    cout<<ans;
    return 0;
}