//Implementation practice 1528C
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int buildEuler(int node, vector<int> G[], vector<pii> &v, int startTime) {
    v[node].first = startTime;
    for(auto it: G[node]) {
        startTime = buildEuler(it,G,v,startTime+1) + 1;
    }
    v[node].second = startTime;
    //return EndTime
    return startTime;
}

int recur(int node, vector<int> G[], vector<pii> &timing, set<pii> &st) {
    int ans = 0;
    vector<pii> del; // in case we delete something
    auto upper = st.upper_bound(timing[node]);
    if(upper != st.end()) {
        pii it = *upper;
        if(it.second < timing[node].second)
            st.erase(it), del.push_back(it);
    }
    upper--;
    if(upper != st.begin()) {
        pii it = *upper;
        if(it.second > timing[node].second)
            st.erase(it), del.push_back(it);
    }
    st.insert(timing[node]);
    ans = st.size()-1;
    for(auto it: G[node]) {
        ans = max(ans,recur(it,G,timing,st));    
    }
    for(auto it: del)
        st.insert(it);
    st.erase(timing[node]);
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> A[n], B[n];
    for(int i=0;i<n-1;i++) {
        int a;
        cin>>a;
        A[a-1].push_back(i+1);
    }
    for(int i=0;i<n-1;i++) {
        int a;
        cin>>a;
        B[a-1].push_back(i+1);
    }
    //Step 1: build the euler tour of graph B
    vector<pii> v; //Save euler tour here
    for(int i=0;i<n;i++)
        v.push_back({0,0});
    buildEuler(0,B,v,1);
    //Step 2: call dfs on first tree
    set<pii> st;
    st.insert({-1,-1}); //Avoid dealing with empty set
    cout<<recur(0,A,v,st)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}