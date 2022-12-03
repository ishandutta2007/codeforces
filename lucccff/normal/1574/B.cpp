#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    int a,b,c;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>m;
        if (a+b+c-3<m) {
            cout<<"NO\n";
            continue;
        }
        if (max(a,max(b,c))*2-(a+b+c)-1>m) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}