// as a juruo, i should have went to lck's training
#include <bits/stdc++.h>
using namespace std;
const int mxN=3e5+5,alpha=26;
int dp[mxN],pos[mxN],val[mxN],qwq[mxN],nxt[mxN],trie[alpha][mxN],cnt=1;
vector<int> ans;
multiset<int> sus[mxN];
int upd(string s){
    int ptr=0;
    for(int i=0;i<s.length();i++){
        int x=s[i]-'a';
        if(!trie[x][ptr])trie[x][ptr]=cnt++;
        ptr=trie[x][ptr];
    }
    sus[ptr].insert(0);
    qwq[ptr]=0;
    return ptr;
}
void bfs(){
    queue<int> q;
    q.push(0);
    while(q.size()){
        auto e=q.front();
        q.pop();
        for(int i=0;i<alpha;i++){
            if(trie[i][e]){
                nxt[trie[i][e]]=(!e?e:trie[i][nxt[e]]);
                q.push(trie[i][e]);
            }
            else trie[i][e]=trie[i][nxt[e]];
        }
    }
}
int eat(int x){
    if(!x)return -1;
    if(dp[x]!=-1)return dp[x];
    dp[x]=max(qwq[x],eat(nxt[x]));
    if(dp[x]==-1)dp[x]--;
    ans.push_back(x);
    return dp[x];
}
signed main(){
    int n,q;
    cin>>n>>q;
    memset(dp,-1,sizeof dp);
    memset(qwq,-1,sizeof qwq);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        pos[i]=upd(s);
    }
    bfs();
    while(q--){
        int op;
        cin>>op;
        if(op&1){
            int x,v;
            cin>>x>>v;
            x--;
            sus[pos[x]].erase(sus[pos[x]].find(val[x]));
            val[x]=v;
            sus[pos[x]].insert(val[x]);
            qwq[pos[x]]=*sus[pos[x]].rbegin();
            for(auto i:ans)dp[i]=-1;
            ans.clear();
        }
        else{
            string s;
            cin>>s;
            int ptr=0,maxi=-1;
            for(int i=0;i<s.length();i++){
                ptr=trie[s[i]-'a'][ptr];
                maxi=max(maxi,eat(ptr));
            }
            cout<<maxi<<"\n";
        }
    }
}