#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,p,s;
    long long a[200010],b[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>p>>k;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        sort(a,a+n);
        s=0;
        for(j=0;j<n;j+=2) {
            s+=a[j];
            if (s>p) break;
        }
        j-=2;
        m=j;
        s=0;
        for(j=1;j<n;j+=2) {
            s+=a[j];
            if (s>p) break;
        }
        j-=2;
        if (j>m) m=j;
        if (m>n-1) m=n-1;
        cout<<m+1<<endl;
    }
    return 0;
}