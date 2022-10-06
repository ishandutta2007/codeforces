#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define len(v) (int)(v).size()
#define INF 1000000005

using namespace std;

typedef pair<int,int>P;

map<string,int> mp;
map<string,int> hoge;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        set<string> st;
        cin >> s[i];
        rep(j,len(s[i])){
            for(int k = j+1; k <= len(s[i]); k++){
                st.insert(s[i].substr(j,k-j));
            }
        }
        for(auto& it : st){
            if(mp.find(it) == mp.end()){
                hoge[it] = i;
            }
            mp[it]++;
        }
    }
    int q;
    cin >> q;
    rep(i,q){
        string t;
        cin >> t;
        int val = mp[t];
        cout << val << " ";
        if(val){
            cout << s[hoge[t]] << "\n";
        }else{
            cout << "-\n";
        }
    }
}