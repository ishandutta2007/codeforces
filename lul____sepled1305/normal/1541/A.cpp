#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        if(n%2 == 0) {
            for(int i=1;i<=n;i++) {
                if(i%2 == 1) cout<<i+1<<' ';
                else cout<<i-1<<' ';
            }
            cout<<endl;
        }
        else {
            cout<<"3 1 2 ";
            for(int i=4;i<=n;i++) {
                if(i%2 == 0) cout<<i+1<<' ';
                else cout<<i-1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}