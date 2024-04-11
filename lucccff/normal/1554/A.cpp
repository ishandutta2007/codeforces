#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[300010],b[300010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        m=0;
        for(j=0;j<n-1;j++) {
            if (a[j]*a[j+1]>m) m=a[j]*a[j+1];
        }
        cout<<m<<endl;
    }
    return 0;
}