#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        if (n&1) {
            cout<<"Bob\n";
        }
        else {
            l=0;
            while(!(n&1)) {
                l++;
                n>>=1;
            }
            if (n==1&&(l&1)) {
                cout<<"Bob\n";
            }
            else {
                cout<<"Alice\n";
            }
        }
    }
    return 0;
}