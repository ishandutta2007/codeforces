#include<bits/stdc++.h>
using namespace std;

string recur(string s, vector<int> v, int k, int pos, string f, bool over) {
    sort(v.begin(),v.end());
    if(s.size() == pos)
        return f;
        
    if(over) {
        if(v.size() != k) {
            f.push_back('0');
            return recur(s,v,k,pos+1,f,true);
        }
        else {
            f.push_back(v[0]+'0');
            return recur(s,v,k,pos+1,f,true);
        }
    }
        
    if(v.size() == k && v.back() < s[pos]-'0')
        return "";
        
    bool found = false;
    for(auto it: v) {
        if(it == s[pos]-'0')
            found = true;
    }
    if(found) {
        f.push_back(s[pos]);
        string ff = recur(s,v,k,pos+1,f,false);
        if(ff.size() != 0)
            return ff;
        int idx = v.size()-1;
        for(;idx>=0;idx--) {
            if(v[idx] < s[pos]-'0'+1)
                break;
        }
        f.pop_back();
        idx++;
        if(idx == v.size())
            return "";
        if(v[idx] == s[pos]-'0'+1) {
            f.push_back(v[idx]+'0');
            return recur(s,v,k,pos+1,f,true);
        }
        if(v.size() == k) {
            f.push_back(v[idx]+'0');
            return recur(s,v,k,pos+1,f,true);
        }
        if(v.size() != k) {
            v.push_back(s[pos]-'0'+1);
            f.push_back(s[pos]+1);
            return recur(s,v,k,pos+1,f,true);
        }
    }
    if(v.size() != k) {
        v.push_back(s[pos]-'0');
        f.push_back(s[pos]);
        string ff = recur(s,v,k,pos+1,f,false);
        if(ff.size() != 0)
            return ff;
        v.pop_back();
        f.pop_back();
        int tar = s[pos]-'0'+1;
        bool fff = false;
        for(auto it: v) {
            if(it == tar)
                fff = true;
        }
        if(!fff)
            v.push_back(tar);
        f.push_back(tar+'0');
        return recur(s,v,k,pos+1,f,true);
    }
    int mini = 9;
    for(int j = v.size() - 1;j >= 0;j--) {
        if(v[j] < s[pos]-'0')
            break;
        mini = min(mini,v[j]);
    }
    f.push_back(mini+'0');
    return recur(s,v,k,pos+1,f,true);
}

int main() {
    int T; cin>>T;
    while(T--) {
        string s;
        int k;
        cin>>s>>k;
        vector<int> v;
        cout<<recur(s,v,k,0,"",false)<<endl;
    }
    return 0;
}