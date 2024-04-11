#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s;
    long long a[200010],b[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k>>m;
        for(j=0;j<m;j++) {
            cin>>b[j];
        }
        if ((n-m)%(k-1)!=0) {
            cout<<"NO\n";
            continue;
        }
        if (n==m) {
            cout<<"YES\n";
            continue;
        }
        k=(k-1)/2;
        for(j=0;j<m;j++) {
            if (b[j]-j-1>=k&&n-b[j]-m+j+1>=k) {
                cout<<"YES\n";
                break;
            }
        }
        if (j==m) cout<<"NO\n";
    }
    return 0;
}