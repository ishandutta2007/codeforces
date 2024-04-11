#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int MN=4e5+10;
set<pair<int, int> > g[MN];
void dele(int a, int b, int i){
    g[a].erase({b, i});
    g[b].erase({a, i});
}

void dfs(int x, vector<int>&ec){
    int t=x;
    vector<int> tc;
    vector<int> es;
    while (1){
        tc.push_back(t);
        auto nx=*g[t].begin();
        dele(t, nx.F, nx.S);
        t=nx.F;
        es.push_back(nx.S);
        if (t==x) break;
    }
    for (int i=0;i<(int)tc.size();i++){
        if (g[tc[i]].size()>0){
            dfs(tc[i], ec);
        }
        ec.push_back(es[i]);
    }
}

int has[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x*2].insert({y*2+1, i});
        g[y*2+1].insert({x*2, i});
    }
    vector<pair<pair<int, int>, int> > re;
    vector<int> o;
    for (int i=0;i<MN;i++){
        if (g[i].size()%2==1){
            o.push_back(i);
        }
    }
    while (!o.empty()){
        int x=o.back();
        o.pop_back();
        if (g[x].size()%2==1){
            auto nx=*g[x].begin();
            dele(x, nx.F, nx.S);
            re.push_back({{x, nx.F}, nx.S});
            if (g[nx.F].size()%2==1){
                o.push_back(nx.F);
            }
        }
    }
    string v(n, ' ');
    for (int i=0;i<MN;i++){
        if (g[i].size()>0){
            vector<int> ec;
            dfs(i, ec);
            for (int ii=0;ii<(int)ec.size();ii++){
                if (ii%2) v[ec[ii]]='r';
                else v[ec[ii]]='b';
            }
        }
    }
    for (int i=re.size()-1;i>=0;i--){
        if (has[re[i].F.S]>0){
            v[re[i].S]='r';
            has[re[i].F.S]--;
            has[re[i].F.F]--;
        }
        else{
            v[re[i].S]='b';
            has[re[i].F.S]++;
            has[re[i].F.F]++;
        }
    }
    cout<<v<<endl;
}