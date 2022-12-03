#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s;
    long long a[300010],b[300010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        s=0;
        m=0;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        sort(a,a+n);
        s=a[n-1];
        for(j=0;j<n-1;j++) {
            s+=(a[j]-a[j+1])*(j+1)*(n-j-1);
        }
        cout<<s<<endl;
    }
    return 0;
}