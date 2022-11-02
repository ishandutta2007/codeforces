#include <bits/stdc++.h>
using namespace std;

string ss[2] = {"NO","YES"};

int main() {
    int T; cin>>T;
    while(T--) {
        string s; cin>>s;
        int pass = 1, ct1 = 0, ct2 = 0;
        for(auto it: s) {
            if(it == 'A') ct1++;
            else ct2++;
            if(ct1 < ct2) {
                pass = 0;
            }
        }
        pass = (pass & (s[s.size()-1] == 'B'));
        cout<<ss[pass]<<'\n';
    }
    return 0;
}