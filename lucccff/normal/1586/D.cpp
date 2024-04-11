#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010],b[100010],c[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>n;
    for(i=1;i<=n;i++) {
        cout<<"? ";
        for(j=1;j<=n;j++) {
            if (i==j) cout<<2<<' ';
            else cout<<1<<' ';
        }
        cout<<endl<<flush;
        cin>>k;
        if (k!=i) {
            a[i]=k;
            b[k]=i;
        }
    }
    for(i=1;i<=n;i++) {
        cout<<"? ";
        for(j=1;j<=n;j++) {
            if (i==j) cout<<1<<' ';
            else cout<<2<<' ';
        }
        cout<<endl<<flush;
        cin>>k;
        if (k!=i) {
            b[i]=k;
            a[k]=i;
        }
    }
    k=0;
    for(i=1;i<=n;i++) {
        k=a[k];
        c[k]=i;
    }
    cout<<"! ";
    for(i=1;i<=n;i++) {
        cout<<c[i]<<' ';
    }
    cout<<endl<<flush;
    return 0;
}