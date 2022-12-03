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
        LL x,y;
        cin>>x>>y;
        if (x>y) cout<<x+y<<endl;
        else if (y%x==0) cout<<x<<endl;
        else cout<<(x*(y/x)+y)/2<<endl;
    }
    return 0;
}