#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
int bit[N];
int n;
 
int update(int p, int val) {
    for(;p <= n; p |= (p+1)) bit[p] += val;
}
 
int ssum(int r) {
    int cum = 0;
    for(;r >= 0;r = (r&(r+1)) - 1)
        cum += bit[r];
    return cum;
}
 
int main() {
    int T; cin>>T;
    while(T--) {
        cin>>n;
        string s, t;
        cin>>s>>t;
        ll sum = 0;
        ll ans = 1e18;
        vector<int> pos[26];
        bool del[n];
        for(int i=0;i<n;i++) {
            pos[s[i]-'a'].push_back(i);
            del[i] = false;
            bit[i] = 0;
        }
        bit[n] = 0;
        for(int i=0;i<26;i++)
            reverse(pos[i].begin(),pos[i].end());
        int pointer = 0;
        for(int i=0;i<n;i++) {
            if(sum > ans)
                break;
 
            while(del[pointer])
                pointer++;
 
            for(int j=0;j<t[i]-'a';j++) {
                if(pos[j].empty())
                    continue;
                ans = min(ans, 0LL + pos[j].back() + ssum(n) - ssum(pos[j].back()) - i + sum);
            }
            if(t[i] == s[pointer]) {
                del[pointer] = true;
                pos[t[i]-'a'].pop_back();
            }
            else {
                if(pos[t[i]-'a'].size() != 0) {
                    sum += (pos[t[i]-'a'].back() + ssum(n) - ssum(pos[t[i]-'a'].back()) - i);
                    update(pos[t[i]-'a'].back(),1);
                    del[pos[t[i]-'a'].back()] = true;
                    pos[t[i]-'a'].pop_back();
                }
                else {
                    break;
                }
            }
        }
        if(ans > 1e17)
            ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}