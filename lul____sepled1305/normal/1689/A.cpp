#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--) {
        int n,m,k; cin>>n>>m>>k;
        string s,t; cin>>s>>t;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        int rn = -1, ct = 0;
        string ans = "";
        // cout<<s<<'\n'<<t<<'\n';
        while(true) {
            if(s.empty() || t.empty())
                break;
            if(ct == k) {
                ct = 1;
                if(rn == 1) {
                    ans.push_back(t.back()); t.pop_back();
                    rn = 2;
                }
                else {
                    ans.push_back(s.back()); s.pop_back();
                    rn = 1;
                }
            }
            else {
                // cout<<s.back()<<' '<<t.back()<<endl;
                if(s.back() < t.back()) {
                    if(rn == 1) {
                        ct++;
                    }
                    else {
                        rn = 1; ct = 1;
                    }
                    ans.push_back(s.back());
                    s.pop_back();
                }
                else {
                    if(rn == 1) {
                        rn = 2; ct = 1;
                    }
                    else {
                        ct++;
                    }
                    ans.push_back(t.back());
                    t.pop_back();
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}