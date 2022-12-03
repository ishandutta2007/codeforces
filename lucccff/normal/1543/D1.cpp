#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k;
        m=0;
        for(j=0;j<n;j++) {
            cout<<(j^m)<<endl<<flush;
            cin>>l;
            if (l==1) break;
            m=j;
        }
    }
    return 0;
}