#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    int a,b;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>a>>b;
        if (abs(a-b)&1) {
            cout<<-1<<endl;
            continue;
        }
        if (a==b&&a==0) cout<<0<<endl;
        else if (a==b) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}