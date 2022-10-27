#include<bits/stdc++.h>
using namespace std;
int n,m,t;
map<string,int> f;
map<long long,int> b;
long long g[41];
set<int> s;
string ss;
int dfs(long long mask){
    if(b.count(mask))return b[mask];
    int p=__builtin_ctzll(mask);
    return b[mask]=max(dfs(mask^(1LL<<p)),dfs(mask&g[p])+1);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>m>>n;
    int id=0;
    for(int i=0;i<n;i++)
        g[i]=((1LL<<n)-1);
    for(int i=1;i<=m;i++){
        cin>>t;
        if(t==1){
            vector<int> a;
            for(int i:s)
                a.push_back(i);
            for(int i=0;i<a.size();i++)
            for(int j=0;j<a.size();j++){
                if((g[a[i]]&(1LL<<(a[j]))))
                g[a[i]]^=(1LL<<(a[j]));
            }
            s.clear();
            }
        else{
            cin>>ss;
            if(!f.count(ss))
                f[ss]=id++;
            s.insert(f[ss]);
        }
    }
    if(!s.empty()){
        for(int i:s)
            for(int j:s)
            if(g[i]&(1LL<<j))
            g[i]^=(1LL<<j);
    }
    b[0]=0;
    cout<<dfs((1LL<<n)-1)<<'\n';
}