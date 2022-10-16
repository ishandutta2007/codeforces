#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m,u,v;cin>>n>>m;
    set<long long int>arr[7],brr[6];
    for(int i=0;i<m;i++){
        cin>>u>>v;u--;v--;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    if(n<7){
        cout<<m<<"\n";
        return;
    }
    int ans = 0;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            int k = 0;
            int val = 0;
            for(int i=0;i<7;i++){
                if(i!=j){
                    brr[k]=arr[i];
                    k++;
                }   
            }
            for(auto p:arr[j]){
                brr[i].insert(p);
            }
            for(int oo=0;oo<6;oo++){
                if(brr[oo].find(j)!=brr[oo].end()){
                    brr[oo].erase(j);
                    brr[oo].insert(i);
                }
            }
            for(auto i:brr){
                val+=i.size();
            }
            ans=max(ans,(val+1)/2);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}