#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n,s; cin>>n>>s;
        if(n == 1)
            cout<<s<<endl;
        else
            cout<<(s/(n-(n-1)/2))<<endl;
    }
    return 0;
}