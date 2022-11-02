#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<int> g1[101010];
vector<int> g2[101010];
int used[101010];
int cc[101010];

void dfs1(int x, int c){
    if (used[x]) return;
    cc[x]=c;
    used[x]=1;
    for (int nx:g1[x]){
        dfs1(nx, c);
    }
}

int cl[101010];

void dfs2(int x, int co){
    if (cl[x]>0){
        if (cl[x]!=co){
            cout<<0<<endl;
            exit(0);
        }
        return;
    }
    cl[x]=co;
    for (int nx:g2[x]){
        dfs2(nx, 3-co);
    }
}

ll mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int, int> > e2;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if (c==1){
            g1[a].push_back(b);
            g1[b].push_back(a);
        }
        else{
            e2.push_back({a, b});
        }
    }
    int ccs=0;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            dfs1(i, ccs++);
        }
    }
    for (auto e:e2){
        if (cc[e.F]==cc[e.S]){
            cout<<0<<endl;
            return 0;
        }
        else{
            g2[cc[e.F]].push_back(cc[e.S]);
            g2[cc[e.S]].push_back(cc[e.F]);
        }
    }
    ll v=1;
    for (int i=0;i<ccs;i++){
        if (cl[i]==0){
            dfs2(i, 1);
            v*=2ll;
            v%=mod;
        }
    }
    cout<<(v*500000004ll)%mod<<endl;
}