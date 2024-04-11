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
        k=0;
        while(n!=0) {
            l=n%10;
            n=n/10;
            if (l>k) k=l;
        }
        cout<<k<<endl;
    }
    return 0;
}