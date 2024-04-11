#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a,b;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>a>>b;
        if (a-b!=0) {
            cout<<abs(a-b)<<' ';
            if (a-a/abs(a-b)*abs(a-b)<a/abs(a-b)*abs(a-b)+abs(a-b)-a) {
                cout<<a-a/abs(a-b)*abs(a-b)<<endl;
            }
            else {
                cout<<a/abs(a-b)*abs(a-b)+abs(a-b)-a<<endl;
            }
        }
        else cout<<0<<' '<<0<<endl;
    }
    return 0;
}