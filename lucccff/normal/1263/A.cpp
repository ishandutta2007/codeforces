#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,a,b,c;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>a>>b>>c;
        if (a+b<c) {
            cout<<a+b<<endl;
            continue;
        }
        if (a+c<b) {
            cout<<a+c<<endl;
            continue;
        }
        if (c+b<a) {
            cout<<c+b<<endl;
            continue;
        }
        cout<<(a+b+c)/2<<endl;
    }
    return 0;
}