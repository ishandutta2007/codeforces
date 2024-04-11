#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010],b[100010],c[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    for(i=1;i<n;i++) {
        b[i]=a[i]-a[i-1];
    }
    k=a[0];
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    for(i=1;i<n;i++) {
        c[i]=a[i]-a[i-1];
    }
    sort(b+1,b+n);
    sort(c+1,c+n);
    if (k==a[0]) {
        for(i=1;i<n;i++) {
            if (b[i]!=c[i]) break;
        }
        if (i==n) cout<<"Yes";
        else cout<<"No";
    }
    else {
        cout<<"No";
    }
    return 0;
}