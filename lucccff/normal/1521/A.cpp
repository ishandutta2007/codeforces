#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>m>>n;
        if (n==1) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES\n";
            cout<<(n+1)*m<<' '<<m*(3*n-1)<<' '<<m*n*4<<endl;
        }
    }
    return 0;
}