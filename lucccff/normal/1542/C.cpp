#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[1000];
    k=1;
    n=0;
    while(k<=1e16) {
        n++;
        k=k*n/__gcd(k,n);
        a[n]=k;
    }
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>k;
        m=k;
        for(j=1;j<=n;j++) {
            m=(m+k/a[j])%MOD;
        }
        cout<<m<<endl;
    }
    return 0;
}