#pragma GCC optimize(3)
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<algorithm>
#define ri register int
using namespace std;
typedef long long ll;
int l,m,n,op,s;
ll a[51];
vector<set<int> >v;
map<ll,int>f;
map<string,int>p;
int dfs(ll k){
    if(f.find(k)!=f.end())return f[k];
    ri b,c,t=0;
    while(!((k>>t)&1))++t;
    b=dfs(k^(1ll<<t)),c=dfs(k&a[t]);
    return f[k]=max(b,c+1);
}
main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    while(n--){
        cin>>op;
        if(op&1){
            set<int> r;
            v.push_back(r);
        }
        else{
            string str;
            cin>>str;
            if(p.find(str)==p.end())p[str]=s++;
            v.back().insert(p[str]);
        }
    }
    fill(a,a+m,(1ll<<m)-1);
    l=v.size();
    for(ri i=0;i<l;++i)
        for(auto j:v[i])
            for(auto k:v[i])
                a[j]&=~(1ll<<k);
    f[0]=0;
    cout<<dfs((1ll<<m)-1);
}