#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        bool pass = true;
        for(int i=0;i<min(3000,n);i++) {
            bool local = false;
            for(int j=0;j<=i;j++) {
                if(a[i]%(j+2) != 0)
                    local = true;
            }
            pass = pass & local;
        }
        if(pass)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}