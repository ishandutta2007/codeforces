#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const pair<int,int> delta[8]={{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
pair<int,int> eat(pair<int,int> a,pair<int,int> b){return {a.ff+b.ff,a.ss+b.ss};}
signed main(){
    int n;
    cin>>n;
    queue<int> bfs;
    for(int i=0,x;i<n;i++){
        cin>>x;
        bfs.push(x);
    }
    map<pair<pair<int,int>,int>,int> mp[205];
    int cnt=0;
    bfs.front()--;
    mp[0][{{0,0},5}]++;
    while(bfs.size()){
        cnt++;
        if(!bfs.front()){
            for(auto i:mp[cnt-1]){
                mp[cnt][{i.ff.ff,(i.ff.ss+1)%8}]+=i.ss;
                mp[cnt][{i.ff.ff,(i.ff.ss+7)%8}]+=i.ss;
            }
            bfs.pop();
        }
        else{
            bfs.front()--;
            for(auto i:mp[cnt-1])mp[cnt][{eat(i.ff.ff,delta[i.ff.ss]),i.ff.ss}]+=i.ss;
        }
    }
    set<pair<int,int> > s;
    for(int i=0;i<=cnt;i++){
        for(auto j:mp[i])s.insert(j.ff.ff);
    }
    cout<<s.size()<<"\n";
}