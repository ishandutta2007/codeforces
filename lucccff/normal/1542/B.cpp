#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,f;
    long long a,b;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>a>>b;
        f=0;
        k=1;
        if (b==1) {
            cout<<"Yes\n";
            continue;
        }
        if (a==1) {
            if (n%b==1) {
                cout<<"Yes\n";
            }
            else {
                cout<<"No\n";
            }
            continue;
        }
        while(n>=k) {
            if (n%b==k%b) {
                f=1;
                break;
            }
            k*=a;
        }
        if (f) {
            cout<<"Yes\n";
        }
        else {
            cout<<"No\n";
        }
    }
    return 0;
}