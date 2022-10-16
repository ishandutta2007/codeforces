#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    int n,a,b;cin>>n;
    stack<pair<int,int>>fro;
    stack<string>ans;
    for(int i=0;i<n;i++){
        cin>>a>>b;a--;b--;
        fro.push({a,b});
    }
    while(fro.size()!=0){
        auto i  = fro.top();
        fro.pop();
        int oo = 0;
        string mid;
        while(ans.size()>0 && oo<i.first){
            mid+=ans.top();
            oo+=ans.top().size();
            ans.pop();
        }
        if(oo>i.second || oo<i.first){
            cout<<"IMPOSSIBLE"<<"\n";
            return;
        }
        ans.push('('+mid+')');
    }
    while(ans.size()>0){
        cout<<ans.top();
        ans.pop();
    }
    cout<<"\n";
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