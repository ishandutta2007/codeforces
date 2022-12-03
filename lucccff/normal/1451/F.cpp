#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[110][110],b[210];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        memset(b,0,sizeof(b));
        for(j=0;j<n;j++) {
            for(k=0;k<m;k++) {
                cin>>a[j][k];
                b[j+k]^=a[j][k];
            }
        }
        for(j=0;j<n+m-1;j++) {
            if (b[j]!=0) {
                break;
            }
        }
        if (j!=n+m-1) {
            cout<<"Ashish\n";
        }
        else {
            cout<<"Jeel\n";
        }
    }
    return 0;
}