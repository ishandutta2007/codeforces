/**
    RIP IM 2020-2021
    Hi M 2019-2020, 2021-
**/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        string s, t;
        cin>>s>>t;
        int n = s.size();
        bool pass = false;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                bool rev = false, ps = true;
                int pointer = i, k = 0;
                while(pointer >= 0 && k != t.size()) {
                    if(pointer == j)
                        rev = true;
                    if(t[k] != s[pointer]) {
                        ps = false;
                        //cout<<i<<' '<<j<<' '<<k<<endl;
                        break;
                    }
                    k++;
                    if(rev)
                        pointer--;
                    else
                        pointer++;
                }
                if(ps && k == t.size()) {
                    pass = true;
                    break;
                }
            }
            if(pass)
                break;
        }
        if(pass)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}