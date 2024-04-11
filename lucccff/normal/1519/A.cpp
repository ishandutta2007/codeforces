#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,r,b,d;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>r>>b>>d;
        if ((b==0)&&(r==0)) {
            cout<<"YES\n";
            continue;
        }
        if ((b==0)||(r==0)) {
            cout<<"NO\n";
            continue;
        }
        if (r>b) {
            if (r>(d+1)*b) {
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
            }
        }
        else {
            if (b>(d+1)*r) {
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
            }
        }
    }
    return 0;
}