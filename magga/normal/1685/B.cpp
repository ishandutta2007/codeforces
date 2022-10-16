#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
void solve(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll count[2]{0};
    string s;cin>>s;
    ll n = s.size();
    for(auto i:s) count[i-'A']++;
    if((count[0]!=a+c+d) || (count[1]!=b+c+d)){
        cout<<"NO"<<"\n";
        return;
    }
    int curr = 1;
    char start = s[0];
    vector<pair<ll,char>>arr[2];
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]) curr++;
        else{
            arr[curr&1].push_back({curr,start});
            start = s[i];
            curr = 1;
        }
    }
    arr[curr&1].push_back({curr,start});
    sort(arr[0].begin(),arr[0].end());
    int excess = 0;
    for(auto i:arr[0]){
        auto p = i.F/2;
        if(i.S=='A' && c>0){
            int to = min(p,c);
            c-=to;
            p-=to;
        }else if(i.S=='B' && d>0){
            int to = min(p,d);
            d-=to;
            p-=to;
        }
        if(p>0) p--;
        excess+=p;
    }
    
    for(auto i:arr[1]){
        excess += i.F/2;
    }
    if(c+d>excess){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
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