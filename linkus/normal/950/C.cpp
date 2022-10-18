#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    set<int> pos[2];
    FOR(i,0,s.size()){
        pos[s[i]-48].insert(pos[s[i]-48].end(),i);
    }
    vector<vector<int>> ans;
    while(!pos[0].empty()){
//        whatis(*pos[0].begin())
        int cur = *pos[0].begin(),wh = 1;
        pos[0].erase(pos[0].begin());
        ans.push_back({cur});
        for(;;){
            auto it = pos[wh].lower_bound(cur);
//            whatis(*it)
            if(it == pos[wh].end()){
                if(wh == 0) REE(-1)
                break;
            }
            ans.back().push_back(*it);
            cur = *it;
            pos[wh].erase(it);
            wh ^= 1;
        }
    }
    if(!pos[1].empty()) REE(-1)
    cout << ans.size() << '\n';
    FORR(i,ans){
        cout << i.size() << ' ';
        FORR(x,i)
            cout << x+1 << ' ';
        cout << '\n';
    }
}