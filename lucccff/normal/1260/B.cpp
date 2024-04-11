#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        if (n>2*m||n*2<m) {
            cout<<"NO\n";
            continue;
        }
        if (m>n) {
            l=m;
            m=n;
            n=l;
        }
        m-=n-m;
        if (m%3!=0) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}