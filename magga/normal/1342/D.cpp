#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    map<int,set<pair<int,int>>>s;
    int co[200001]{0};
    int n,k,d;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>d;
        co[d]++;
    }
    for(int i=1;i<=k;i++){
        cin>>d;
        if(co[i]!=0)
            s[d].insert({-1*i,co[i]});
    }
    int curr = 0;
    vector<vector<int>>v;
    vector<int>em;
    vector<pair<int,int>>dump;
    vector<pair<pair<int,int>,pair<int,int>>>chang;
    vector<int>keys;
    while(s.size()>0){
        v.push_back(em);
        curr = 0;
        keys.clear();
        int cap = 0;
        for(auto &i:s){
            cap=i.first;
            dump.clear();
            chang.clear();
            for(auto &j:i.second){
                if(curr==cap) break;
                for(int k=0;k<min(j.second,cap-curr);k++){
                    v[v.size()-1].push_back(-1*j.first);
                }
                if(j.second==min(j.second,cap-curr)){
                    dump.push_back(j);
                }else
                chang.push_back({j,{j.first,j.second-min(j.second,cap-curr)}});
                curr+=min(j.second,cap-curr);
            }
            for(auto po:dump){
                s[i.first].erase(po);
            }
            for(auto po:chang){
                s[i.first].erase(po.first);
                s[i.first].insert(po.second);
            }
            if(s[i.first].size()==0){
                keys.push_back(i.first);
            }
        }
        for(auto i:keys){
            s.erase(i);
        }
    }
    int oo = 0;
    for(auto &i:v){
        if(i.size()==0){
            oo++;
        }
    }
    cout<<v.size()-oo<<"\n";
    for(int i=0;i<v.size()-oo;i++){
        cout<<v[i].size()<<" ";
        for(auto p : v[i] ){
            cout<<p<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    solve();
}