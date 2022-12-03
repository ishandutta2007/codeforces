#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010],b[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,r,s;
    cin>>t;
    while(t--) {
        cin>>n>>l>>r>>k;
        s=0;
        m=0;
        for(i=0;i<n;i++) {
            cin>>j;
            if (j>=l&&j<=r) a[m++]=j;
        }
        sort(a,a+m);
        for(i=0;i<m;i++) {
            s+=a[i];
            if (s>k) break;
        }
        cout<<i<<endl;
    }
    return 0;
}