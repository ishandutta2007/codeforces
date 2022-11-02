#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        map<char,int> mp;
        map<char,int> ch;
        vector<char> v;
        string s; cin>>s;
        for(int i=s.size()-1;i>=0;i--) {
            if(mp.count(s[i]) == 0) {
                v.push_back(s[i]);
            }
            mp[s[i]]++;
        }
        bool pass = true;
        for(int i=0;i<v.size();i++) {
            if(mp[v[i]]%(v.size()-i) != 0)
                pass = false;
            ch[v[i]] = mp[v[i]]/(v.size()-i);
        }
        if(!pass) {
            cout<<"-1\n";
            continue;
        }
        //cout<<"FF\n";
        int counti = 0;
        int i = 0;
        for(;i<s.size();i++) {
            if(counti == v.size())
                break;
            //cout<<i<<' '<<s[i]<<' '<<ch[s[i]]<<' '<<counti<<endl;
            ch[s[i]]--;
            if(ch[s[i]] < 0) {
                pass = false;
                break;
            }
            if(ch[s[i]] == 0) 
                counti++;
        }
        if(!pass) {
            cout<<"-1\n";
            continue;
        }
        //cout<<"FF\n";
        //Let's make a trial string
        string ss;
        for(int j=0;j<i;j++)
            ss.push_back(s[j]);
        string rr;
        set<char> h;
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<ss.size();j++) {
                if(h.count(ss[j]) == 0)
                    rr.push_back(ss[j]);
            }
            h.insert(v[i]);
        }
        if(rr == s) {
            cout<<ss<<' ';
            for(auto it: v)
                cout<<it;
            cout<<endl;
        }
        else {
            cout<<"-1\n";
        }
    }
}