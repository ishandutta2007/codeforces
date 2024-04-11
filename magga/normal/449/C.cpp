#include<bits/stdc++.h>
using namespace std;
#define MAXN   1000001 
int spf[MAXN];  
void sieve(){ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){  
        if (spf[i] == i){  
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}  
void pre(){
    sieve();
}
void solve(){
    int n;cin>>n;
    map<int,set<int>>m;
    for(int i=2;i<=n;i++) m[spf[i]].insert(i);
    bool flag = false;
    int val = 0;
    for(auto &i:m){
        if(i.second.size()%2==0) continue;
        if(!flag && i.first*2<=n){
            flag=1;
            val=i.first;
        }else if(flag && i.first*2<=n){
            m[2].erase(2*val);
            m[val].insert(2*val);
            m[2].erase(2*i.first);
            m[i.first].insert(2*i.first);
            flag=0;
        }
    }
    vector<pair<int,int>>v;
    for(auto i:m){
        int j=0,k=0;
        for(auto ii:i.second){
            j++;
            if(j%2==0){
                v.push_back({ii,k});
            }else{
                k=ii;
            }
        }
    }
    cout<<v.size()<<"\n";
    for(auto i:v){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    //*/
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}