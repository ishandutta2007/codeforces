#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long double x=0,y=0;
    pair<long double,long double>arr[n];
    set< pair<long double,long double>>s;
    for(long long int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        x+=arr[i].first;
        y+=arr[i].second;
        s.insert(arr[i]);
    }
    x=(x*(1.0))/n;
    y=(y*(1.0))/n;
    for(long long int i=0;i<n;i++){
        if(s.find(make_pair(x+(x-arr[i].first),y+(y-arr[i].second)))==s.end()){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
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