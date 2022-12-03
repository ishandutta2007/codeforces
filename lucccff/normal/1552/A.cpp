#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    char c[50],a[50],ch;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>c[j];
            a[j]=c[j];
        }
        sort(a,a+n);
        k=0;
        for(j=0;j<n;j++) {
            if (a[j]!=c[j]) k++;
        }
        cout<<k<<endl;
    }
    return 0;
}