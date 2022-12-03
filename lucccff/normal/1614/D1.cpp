#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

LL a[5000010],b[5000010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    LL ans=0;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>k;
        a[k]++;
    }
    for(i=1;i<=5e6;i++) {
        for(j=i+i;j<=5e6;j+=i) {
            a[i]+=a[j];
        }
        a[i]*=i;
    }
    for(i=1;i<=5e6;i++) {
        b[i]=max(b[i],a[i]);
        for(j=i+i;j<=5e6;j+=i) {
            b[j]=max(b[j],a[j]-a[j]/j*i+b[i]);
        }
        ans=max(b[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}