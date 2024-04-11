#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,f;
    long long a[100010],b[100010],c[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
            if (j&1) b[j/2]=a[j];
            else c[j/2]=a[j];
        }
        sort(b,b+n/2);
        sort(c,c+(n+1)/2);
        for(j=0;j<n;j++) {
            if (j&1) a[j]=b[j/2];
            else a[j]=c[j/2];
        }
        f=0;
        for(j=1;j<n;j++) {
            if (a[j]<a[j-1]) {
                f=1;
                break;
            }
        }
        if (f) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}