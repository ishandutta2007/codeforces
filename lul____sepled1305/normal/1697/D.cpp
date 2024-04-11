//
// Created by Nitit Jongsawatsataporn on 13/6/2022 AD.
//

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int last[26];
int ct = 0;

int ask(vector<pii> &v, int idx, int cur) {
    if(idx == v.size())
        return 1;
    cout<<"? 2 "<<v[idx].first<<' '<<cur<<'\n';
    fflush(stdout);
    int a; cin>>a;
    return a;
}

int main() {

    int n; cin>>n;
    string s;
    for(int i=0;i<n;i++) {
        vector<pii> v;
        for(int i=0;i<26;i++) {
            if(last[i] != 0)
                v.push_back({last[i],i});
        }
        sort(v.begin(),v.end(), greater<pii>());
        int l = 0, r = v.size();

        char cur;
        while(l < r) {
            int md = l+r >> 1;
            if(l == md) {
                if(l == v.size()-1) {
                    int a = ask(v,l,i+1);
                    if(a == v.size())
                        r = l;
                    else
                        l = r;
                }
                else {
                    int a = ask(v,l,i+1);
                    if(a == l+1) {
                        r = l;
                    }
                    else {
                        l = r;
                    }
                }
            }
            else {
                int a = ask(v,md,i+1);
                if(a == md+1) {
                    r = md;
                }
                else {
                    l = md+1;
                }
            }
        }
        if(l == v.size()) {
            cout<<"? 1 "<<i+1<<'\n';
            fflush(stdout);
            cin>>cur;
            last[cur-'a'] = i+1;
        }
        else {
            cur = v[l].second+'a';
            last[cur-'a'] = i+1;
        }
        s.push_back(cur);
    }
    cout<<"! "<<s<<'\n';
    fflush(stdout);
    return 0;
}