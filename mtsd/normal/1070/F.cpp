#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define len(v) (v).size()
#define INF 1000000005
using namespace std;
#define int long long 
typedef pair<int,int>P;
signed main(){
    int n;
    cin >> n;
    
    int k=0,p,q,r;
    priority_queue<int>pp,pq;
    deque<int>pr;
    int ans =0;
    rep(i,n){
        string s;
        cin >> s;
        int c;
        cin >> c;
        if(s=="11"){
            k++;
            ans += c;
        }else if(s=="10"){
            pp.push(c);
        }else if(s=="01"){
            pq.push(c);
        }else{
            pr.push_back(c);
        }
    }
    while(!pp.empty()&&!pq.empty()){
        auto x = pp.top();
        auto y = pq.top();
        pq.pop();
        pp.pop();
        ans += x+y;
    }
    vector<int> s;
    s.push_back(0);
    if(pp.empty()){
        while(!pq.empty()){
            auto y = pq.top();
            pq.pop();
            s.push_back(y);
        }
    }else{
        while(!pp.empty()){
            auto x = pp.top();
            pp.pop();
            s.push_back(x);
        }
    }
    for(int i=1;i<s.size();i++){
        s[i] += s[i-1];
    }
    sort(pr.rbegin(),pr.rend());
    pr.push_front(0);
    for(int i=1;i<pr.size();i++){
        pr[i] += pr[i-1];
    }
    int xxx = pr[pr.size()-1];
    for(int i=0;i<=k;i++){
        pr.push_back(xxx);
    }
    xxx = s[s.size()-1];
    for(int i=0;i<=k;i++){
        s.push_back(xxx);
    }
    int tmp = ans;
    for(int i=0;i<=k;i++){
        if(k-i>=s.size()){
            if(i>=pr.size())continue;
            ans = max(ans,tmp+pr[i]);
        }else if(i>=pr.size()){
            ans = max(ans,tmp+s[k-i]);
        }else{
            ans = max(ans,tmp+pr[i]+s[k-i]);
        }
    }
    cout << ans << endl;
    return 0;
}