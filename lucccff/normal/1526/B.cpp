#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        if (n>1222) cout<<"YES\n";
        else {
            int f=0;
            for(j=0;j<=11;j++) {
                if ((n-j*111)>=0&&(n-j*111)%11==0) {
                    f=1;
                    break;
                }
            }
            if (f) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}