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
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        for(j=0;j<n-1;j++) {
            if (a[j]==0&&a[j+1]==1) break;
        }
        if (j<n-1) {
            for(k=0;k<=j;k++) {
                cout<<k+1<<' ';
            }
            cout<<n+1<<' ';
            for(k=j+1;k<n;k++) {
                cout<<k+1<<' ';
            }
            cout<<endl;
            continue;
        }
        for(j=0;j<n;j++) {
            if (a[j]==0) break;
        }
        for(k=j;k<n;k++) {
            cout<<k+1<<' ';
        }
        cout<<n+1<<' ';
        for(k=0;k<j;k++) {
            cout<<k+1<<' ';
        }
        cout<<endl;
    }
    return 0;
}