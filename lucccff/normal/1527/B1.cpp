#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    string s;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>s;
        k=0;
        for(j=0;j<n/2;j++) {
            if (s[j]=='0') k++;
        }
        if (n%2==1) if (s[n/2]=='0') k=-2*k+1;
        if (k>0) {
            cout<<"BOB\n";
        }
        else if (k==0) {
            cout<<"DRAW\n";
        }
        else {
            cout<<"ALICE\n";
        }
    }
    return 0;
}