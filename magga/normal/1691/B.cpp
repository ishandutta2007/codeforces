#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
void solve(){
    int n;cin>>n;
    map<ll,vector<int>>m;
    for(int i=0;i<n;i++){
        int d;cin>>d;
        m[d].push_back(i);
    }
    vector<int>ans(n);
    for(auto i:m){
        if(i.S.size()==1){
            cout<<-1<<"\n";
            return;
        }
        for(int j=0;j<i.S.size();j++){
            ans[i.S[j]] = i.S[(j+1)%i.S.size()];
        }
    }
    for(auto i:ans) cout<<i+1<<" ";
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    for(long long int i=0;i<T;i++){
        solve();
    }   
}