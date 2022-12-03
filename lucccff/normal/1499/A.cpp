#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k1,k2,l,m,n,t,w,b;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k1>>k2;
        cin>>w>>b;
        if (k1>k2) {
            k2+=k1;
            k1=k2-k1;
            k2-=k1;
        }
        l=k1+(int)((k2-k1)/2);
        m=n-k2+(int)((k2-k1)/2);
        if (l<w) cout<<"NO\n";
        else if (m<b) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}