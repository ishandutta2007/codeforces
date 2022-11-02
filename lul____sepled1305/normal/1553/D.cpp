/**
    RIP IM 2020-2021
    Hi M 2019-2020, 2021-
**/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int main() {
    int T;
    cin>>T;
    while(T--) {
        string s,t;
        cin>>s>>t;
        int n = s.size();
        int m = t.size();
        bool pass = false;
        //start with odd
        int p = 0;
        bool odd = (abs(n-m)%2 == 1);
        for(int i=0;i<n;i++) {
            if((i%2 == 1) != odd)
                continue;
            if(p == m)
                break;
            if(s[i] == t[p])
                p++, odd = !odd;
        }
        if(p == m)
            pass = true;
        if(pass)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}