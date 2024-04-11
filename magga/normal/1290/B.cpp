#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n;
set<char> t[2 * N];
set<char>ret;
set<char> combine(set<char>a,set<char>b){
    ret.clear();
    for(auto i:b){
        ret.insert(i);
    }
    for(auto i:a){
        ret.insert(i);
    }
    return ret;
}
void build() {
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1],t[i<<1|1]);
}
set<char> res;
set<char> query(int l, int r) {  // sum on interval [l, r)
    res.clear();
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = combine(t[l++],res);
    if (r&1) res = combine(t[--r],res);
  }
  return res;
}
void pre(){}
void solve(){
    string s;cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        t[i+n].insert(s[i]);
    }
    build();
    int q,u,v;cin>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        if(v-u==0 || s[u-1]!=s[v-1]){
            cout<<"Yes"<<"\n";
            continue;
        }
        auto p = query(u-1,v);
        if(p.size()>2){
            cout<<"Yes"<<"\n";
        }else{
            cout<<"No"<<"\n";
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}