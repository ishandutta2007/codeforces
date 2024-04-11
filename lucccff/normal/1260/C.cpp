#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,r,b;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>r>>b>>k;
        if (r>b) {
            l=r;
            r=b;
            b=l;
        }
        if (b%r==0) {
            if (b!=r) {
                m=b/r-1;
            }
            else {
                m=1;
            }
            if (m<k) {
                cout<<"OBEY\n";
            }
            else {
                cout<<"REBEL\n";
            }
        }
        else {
            if (r%(b-b/r*r)==0) {
                m=b/r;
            }
            else {
                m=b/r+1;
            }
            if (m<k) {
                cout<<"OBEY\n";
            }
            else {
                cout<<"REBEL\n";
            }
        }
    }
    return 0;
}