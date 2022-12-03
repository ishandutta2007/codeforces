#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

LL a[100010],b[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        m=1;
        for(i=0;i<n;i++) {
            cin>>a[i];
            while(a[i]%2==0) {
                a[i]>>=1;
                m<<=1;
            }
        }
        sort(a,a+n);
        m=m*a[n-1];
        for(i=0;i<n-1;i++) {
            m+=a[i];
        }
        cout<<m<<endl;
    }
    return 0;
}