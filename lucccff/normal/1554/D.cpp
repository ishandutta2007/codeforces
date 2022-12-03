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
        if (n%2==0) {
            for(j=0;j<n/2-1;j++) cout<<'a';
            cout<<'b';
            for(j=n/2;j<n;j++) cout<<'a';
            cout<<endl;
        }
        else if (n!=1) {
            for(j=0;j<n/2-1;j++) cout<<'a';
            cout<<'b';
            cout<<'c';
            for(j=n/2+1;j<n;j++) cout<<'a';
            cout<<endl;
        }
        else {
            cout<<'a'<<endl;
        }
    }
    return 0;
}