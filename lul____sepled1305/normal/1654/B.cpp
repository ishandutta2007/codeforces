#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        string s; cin>>s;
        int a[26];
        for(int i=0;i<26;i++) a[i] = 0;
        for(auto it: s)
            a[it-'a']++;
        int idx = -1;
        for(int i=0;i<s.size();i++) {
            idx = i;
            a[s[i]-'a']--;
            if(a[s[i]-'a'] == 0)
                break;
        }
        for(int i=idx;i<s.size();i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}