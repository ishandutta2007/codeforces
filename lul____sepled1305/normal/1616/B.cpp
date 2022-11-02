#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        string s, ans, l; cin>>s;
        l.push_back(s[0]);
        for(int i=1;i<n;i++) {
            if(s[i] <= s[i-1] && i != 1)
                l.push_back(s[i]);
            else if(i == 1 && s[i] < s[i-1])
                l.push_back(s[i]);
            else break;
        }
        for(auto it: l)
            cout<<it;
        reverse(l.begin(),l.end());
        for(auto it: l)
            cout<<it;
        cout<<endl;
    }
    return 0;
}