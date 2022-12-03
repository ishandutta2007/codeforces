#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,ans,p;
    cin>>p;
    for(k=0;k<p;k++){
        cin>>n>>m;
        ans=1;
        t=1;
        for(i=0;i<n;i++) {
            getchar();
            for(j=0;j<m;j++) {
                if (getchar()=='0') {
                    t=0;
                }
                else {
                    ans=(ans<<1)%MOD;
                }
            }
        }
        cout<<(MOD+ans-t)%MOD<<endl;
    }
    return 0;
}