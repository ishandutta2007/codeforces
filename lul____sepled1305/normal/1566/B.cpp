#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int T; cin>>T;
    while(T--) {
        string s; cin>>s;
        bool found = false, f = false;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '0')
                found = true;
            else
                f = true;
                
        }
        if(!found) {
            cout<<0<<endl;
        }
        else {
            if(!f)
                cout<<1<<endl;
            else {
                int sec= 0;
                bool cur = false;
                for(int i=0;i<s.size();i++) {
                	
                    if(s[i] == '0') {
                        if(!cur)
                            sec++;
                        cur = true;
                    }
                    else {
                        cur = false;
                    }
                }
                if(sec == 1)
                    cout<<1<<endl;
                else
                    cout<<2<<endl;
            }
        }
    }
    return 0;
}