#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a,b;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>a>>b;
        if ((a+b)&1) {
            k=min(a,b);
            cout<<k*2+2<<endl;
            for(j=0;j<=k;j++) {
                cout<<j*2+abs(a-b)/2<<' ';
                cout<<j*2+abs(a-b)/2+1<<' ';
            }
        }
        else {
            k=min(a,b);
            cout<<k+1<<endl;
            for(j=0;j<=k;j++) {
                cout<<j*2+abs(a-b)/2<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}