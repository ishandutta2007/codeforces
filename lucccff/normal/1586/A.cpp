#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[210],b[210];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,ans;
    cin>>t;
    while(t--) {
        cin>>n;
        k=0;
        for(i=0;i<n;i++) {
            cin>>a[i];
            k+=a[i];
        }
        l=0;
        for(i=2;i*i<=k;i++) {
            if (k%i==0) {
                l=1;
                break;
            }
        }
        if (l) {
            cout<<n<<endl;
            for(i=0;i<n;i++) {
                cout<<i+1<<' ';
            }
            cout<<endl;
        }
        else {
            m=0;
            for(j=0;j<n;j++) {
                k-=a[j];
                l=0;
                for(i=2;i*i<=k;i++) {
                    if (k%i==0) {
                        l=1;
                        break;
                    }
                }
                if (l&&k>m) {
                    m=k;
                    ans=j;
                }
                k+=a[j];
            }
            cout<<n-1<<endl;
            for(j=0;j<n;j++) {
                if (j!=ans) cout<<j+1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}