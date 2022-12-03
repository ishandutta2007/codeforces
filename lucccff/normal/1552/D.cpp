#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

long long a[20],b[20];

int solve(int n,int k,int i) {
    if (k==0) return 1;
    if (i<n) {
        return max(max(solve(n,k+b[i],i+1),solve(n,k-b[i],i+1)),solve(n,k,i+1));
    }
    else return 0;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        m=0;
        for(j=0;j<n;j++) {
            k=0;
            for(l=0;l<n;l++) {
                if (l!=j) b[k++]=a[l];
            }
            if (solve(n-1,a[j],0)) m=1;
        }
        if (m) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}