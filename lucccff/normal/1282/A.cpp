#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a,b,c,r;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>a>>b>>c>>r;
        if (a>b) {
            a+=b;
            b=a-b;
            a-=b;
        }
        if (c-r<=a) {
            if (c+r>=b) {
                cout<<0<<endl;
            }
            else if (a>c+r) {
                cout<<b-a<<endl;
            }
            else {
                cout<<b-c-r<<endl;
            }
        }
        else {
            if (c-r>=b) {
                cout<<b-a<<endl;
            }
            else if (c+r>=b) {
                cout<<c-r-a<<endl;
            }
            else {
                cout<<b-a-2*r<<endl;
            }
        }
    }
    return 0;
}