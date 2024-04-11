#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        //It can be proved that we don't need to check more than 1000 string
        bool done = false;
        //Check length 1 string
        for(int i=0;i<26;i++) {
            char c = 'a' + i;
            bool found = false;
            for(int j=0;j<s.size();j++) {
                if(s[j] == c) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout<<c<<endl;
                done = true;
                break;
            }
        }
        if(done)
            continue;
        //Check length 2 string
        for(int i=0;i<26;i++) {
            char c = 'a' + i;
            for(int k=0;k<26;k++) {
                char l = 'a' + k;
                bool found = false;
                for(int j=0;j<s.size()-1;j++) {
                    if(s[j] == c && s[j+1] == l) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    cout<<c<<l<<endl;
                    done = true;
                    break;
                }
            }
            if(done)
                break;
        }
        if(done)
            continue;
        //Check length 2 string
        for(int i=0;i<26;i++) {
            char c = 'a' + i;
            for(int k=0;k<26;k++) {
                char l = 'a' + k;
                for(int f=0;f<26;f++) {
                    char cl = 'a' + f;
                    bool found = false;
                    for(int j=0;j<s.size()-2;j++) {
                        if(s[j] == c && s[j+1] == l && s[j+2] == cl) {
                            found = true;
                            break;
                        }
                    }
                    if(!found) {
                        cout<<c<<l<<cl<<endl;
                        done = true;
                        break;
                    }
                }
                if(done)
                    break;
            }
            if(done)
                break;
        }
        if(done)
            continue;
    }
    return 0;
}