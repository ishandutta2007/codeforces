#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int ad = 0;
        if(n%2 == 1) {
            cout<<"1 ";
            ad = 1;
            n--;
        }
        for(int i=0;i<n/2;i++) {
            cout<<2*i+2+ad<<' '<<2*i+1+ad<<' ';
        }
        cout<<endl;
    }
    return 0;
}