#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[300010],b[300010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        l=m=0;
        for(j=0;j<2*n;j++) {
            cin>>k;
            if (k&1) l++;
            else m++;
        }
        if (l==m) {
            cout<<"Yes\n";
        }
        else {
            cout<<"No\n";
        }
    }
    return 0;
}