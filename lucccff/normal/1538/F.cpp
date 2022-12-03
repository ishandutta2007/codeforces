#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i,j,k,l,m,n,t,r;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>l>>r;
        k=0;
        while(r!=0) {
            k+=r-l;
            r=r/10;
            l=l/10;
        }
        cout<<k<<endl;
    }
    return 0;
}