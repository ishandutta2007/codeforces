#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<int> g[101010];
int co[101010];

pair<int, int> dfs1(int x, int c){
    if (co[x]>0){
        if (co[x]!=c){
            cout<<"0 1"<<endl;
            exit(0);
        }
        return {0, 0};
    }
    pair<int, int> r={0, 0};
    co[x]=c;
    if (c==1) r.F=1;
    else r.S=1;
    for (int nx:g[x]){
        auto asd=dfs1(nx, 3-c);
        r.F+=asd.F;
        r.S+=asd.S;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if (m==0){
        cout<<3<<" "<<((ll)n*(ll)(n-1)*(ll)(n-2))/(ll)6<<endl;
        return 0;
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll v=0;
    for (int i=1;i<=n;i++){
        if (co[i]==0){
            auto asd=dfs1(i, 1);
            if (asd.F>1){
                v+=((ll)asd.F*(ll)(asd.F-1))/(ll)2;
            }
            if (asd.S>1){
                v+=((ll)asd.S*(ll)(asd.S-1))/(ll)2;
            }
        }
    }
    if (v>0){
        cout<<1<<" "<<v<<endl;
    }
    else{
        cout<<2<<" "<<(ll)m*(ll)(n-2)<<endl;
    }
}