#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s=0;
    long long a[200010],b[200010];
    cin>>n;
    memset(b,0,sizeof(b));
    for(i=0;i<n;i++) {
        cin>>a[i];
        if (i!=n-1) b[i&1]+=a[i];
        s+=a[i];
    }
    b[2]=b[0]-a[0]+a[n-1];
    for(i=3;i<n;i++) {
        b[i]=b[i-2]-a[i-2]+a[i-3];
    }
    sort(b,b+n);
    cout<<s-b[0];
    return 0;
}