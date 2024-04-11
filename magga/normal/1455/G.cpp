#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
void pre(){}
struct Venice_map{
    long long base = 1e16;
    unordered_map<long long,long long>m;
    multiset<long long>s;
    void addToAll(long long x){
        base += x;
    }
    long long query(long long x){
        return m[x] + base;
    }
    void set(long long a,long long x){
        if(s.find(m[a])!=s.end()) s.erase(s.find(m[a]));
        m[a] = min(m[a],x-base);
        s.insert(m[a]);
    }
    void hardSet(long long a,long long x){
        if(s.find(m[a])!=s.end()) s.erase(s.find(m[a]));
        m[a] = x-base;
        s.insert(m[a]);
    }
    long long minValue(){
        return (*s.begin()) + base;
    }
};
void solve(){
    int n,s;cin>>n>>s;
    vector<Venice_map>st;
    stack<long long>ifConds;
    Venice_map vm;
    st.push_back(vm);
    st[st.size()-1].set(0,0);
    string instruction;
    long long y,v;
    for(int i=0;i<n;i++){
        cin>>instruction;
        if(instruction=="set"){
            cin>>y>>v;
            ll minVal = st[st.size()-1].minValue();
            st[st.size()-1].addToAll(v);
            if(y!=s) st[st.size()-1].set(y,minVal);;
        }else if(instruction=="if"){
            cin>>y;
            long long ref = st[st.size()-1].query(y);
            st.push_back(vm);
            st[st.size()-1].set(y,ref);
            ifConds.push(y);
        }else{
            long long lastIf = ifConds.top();
            ifConds.pop();
            st[st.size()-2].hardSet(lastIf,st[st.size()-1].query(lastIf));
            if(st[st.size()-1].m.size()>st[st.size()-2].m.size()){
                swap(st[st.size()-2],st[st.size()-1]);
            }
            auto k = st.back();
            st.pop_back();
            for(auto i:k.m){
                st[st.size()-1].set(i.F,i.S+k.base);
            }
        }
    }
    cout<<st[0].minValue()<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}