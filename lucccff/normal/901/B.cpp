#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[160],b[160],c[160];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>n;
    a[1]=1;
    b[0]=-1;
    for(i=1;i<n;i++) {
        for(j=0;j<=i;j++) {
            c[j]=a[j];
        }
        for(j=0;j<=i;j++) {
            b[j+1]+=a[j];
        }
        for(j=0;j<=i+1;j++) {
            a[j]=b[j];
            b[j]=c[j];
        }
    }
    cout<<n<<endl;
    for(i=0;i<=n;i++) {
        cout<<(a[i]&1)<<' ';
    }
    cout<<endl;
    cout<<n-1<<endl;
    for(i=0;i<=n-1;i++) {
        cout<<(b[i]&1)<<' ';
    }
    cout<<endl;
    return 0;
}