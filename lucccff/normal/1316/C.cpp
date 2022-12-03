#include <bits/stdc++.h>
#define MOD1 998244353
#define MOD2 1000000009
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s,p;
    long long a[1000010],b[1000010];
    cin>>n>>m>>p;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    for(i=0;i<m;i++) {
        cin>>b[i];
    }
    for(i=0;i<n;i++) {
        if (a[i]%p!=0) break;
    }
    for(j=0;j<m;j++) {
        if (b[j]%p!=0) break;
    }
    cout<<i+j;
    return 0;
}