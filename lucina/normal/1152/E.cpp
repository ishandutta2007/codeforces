#include<bits/stdc++.h>
using namespace std;
struct Eulertour{
    vector<vector<pair<int,int>>> a;
    vector<int> deg;
    vector<int> pt;
    int n,id;
    void add_edge(int u,int v){
        a[u].push_back({v,++id});
        a[v].push_back({u,id});
        deg[u]++;deg[v]++;
    }
    Eulertour(int _n){
        a.resize(_n+5);
        deg.resize(_n+5,0);
        pt.resize(_n+5,0);
        n=_n;
        id=0;
    }
    pair<bool,int> ok(bool tour){
        int odd=0;
        int mark=1;
        for(int i=1;i<=n;i++){
            if(deg[i]&1){
                odd++;
                mark=i;
            }
        }
        return tour?make_pair(odd==0,mark):make_pair(((odd==2)||(odd==0)),mark);
    }
    vector<int> tour(int nod){
        vector<int> path;
        vector<int> st;
        vector<bool> rem(id+2,false);
        st.push_back(nod);
        while(!st.empty()){
            int p=st.back();
            int q=-1;
            while(pt[p]<deg[p]&&q==-1){
                if(!rem[a[p][pt[p]].second]){
                    q=a[p][pt[p]].first;
                    rem[a[p][pt[p]].second]=true;
                }
                ++pt[p];
            }
            if(q==-1){
                st.pop_back();path.push_back(p);
            }
            else{
                st.push_back(q);
            }
        }
        return path;
    }
};
const int maxn=1e5+10;
int n,b[maxn],c[maxn];
vector<int> v;


int main(){
    scanf("%d",&n);
    int pt=0;
    v.push_back(0);
    for(int i=1;i<n;i++){
        scanf("%d",&b[i]);
        v.push_back(b[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d",&c[i]);
        if(b[i]>c[i])return !printf("-1");
        v.push_back(c[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    Eulertour euler((int)v.size());
    for(int i=1;i<n;i++){
        int it=lower_bound(v.begin(),v.end(),b[i])-v.begin();
        int it2=lower_bound(v.begin(),v.end(),c[i])-v.begin();
        euler.add_edge(it,it2);
    }
    auto tt=euler.ok(0);
    if(!tt.first){
        return !printf("-1");
    }
    vector<int> ans=euler.tour(tt.second);
    if((int)ans.size()!=n)return !printf("-1");
    for(auto i:ans){
        printf("%d ",v[i]);
    }


}