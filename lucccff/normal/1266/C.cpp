#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    cin>>n>>m;
    if (n==1&&m==1) {
        cout<<0;
        return 0;
    }
    if (m==1) {
        for(i=0;i<n;i++) {
            cout<<i+2<<endl;
        }
        return 0;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cout<<(i+1)*(j+n+1)<<' ';
        }
        cout<<endl;
    }
    return 0;
}