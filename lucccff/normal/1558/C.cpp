#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,f;
    int a[2050];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        f=0;
        for(j=1;j<=n;j++) {
            cin>>a[j];
            if ((a[j]&1)!=(j&1)) f=1;
        }
        if (f) {
            cout<<-1<<endl;
            continue;
        }
        cout<<n/2*5<<endl;
        for(j=0;j<n/2;j++) {
            for(k=1;k<=n-j*2;k++) {
                if (a[k]==n-j*2) break;
            }
            cout<<k<<' ';
            for(l=1;l<=k/2;l++) {
                swap(a[l],a[k-l+1]);
            }
            for(k=1;k<=n-j*2;k++) {
                if (a[k]==n-j*2-1) break;
            }
            cout<<k-1<<' ';
            for(l=1;l<k/2;l++) {
                swap(a[l],a[k-l]);
            }
            cout<<k+1<<' ';
            for(l=1;l<=k/2;l++) {
                swap(a[l],a[k-l+2]);
            }
            cout<<3<<' ';
            swap(a[1],a[3]);
            k=n-j*2;
            cout<<k<<' ';
            for(l=1;l<=k/2;l++) {
                swap(a[l],a[k-l+1]);
            }
        }
        cout<<endl;
    }
    return 0;
}