#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x;
    long long a[200010],b[200010];
    cin>>n>>k>>x;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    m=0;
    for(i=0;i<n-1;i++) {
        if (a[i+1]-a[i]>x) {
            b[m++]=(a[i+1]-a[i]-1)/x;
        }
    }
    sort(b,b+m);
    for(i=0;i<m;i++) {
        if (k<b[i]) break;
        k-=b[i];
    }
    cout<<m-i+1;
    return 0;
}