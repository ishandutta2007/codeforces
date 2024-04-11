#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    int a[200010],b[200010];
    cin>>t;
    while(t--) {
        cin>>n;
        for(i=0;i<n;i++) {
            for(j=0;j<i;j++) {
                cout<<'(';
            }
            for(j=0;j<i;j++) {
                cout<<')';
            }
            for(j=i;j<n;j++) {
                cout<<'(';
            }
            for(j=i;j<n;j++) {
                cout<<')';
            }
            cout<<endl;
        }
    }
    return 0;
}