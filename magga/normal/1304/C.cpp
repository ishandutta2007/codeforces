#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m;cin>>n>>m;
    pair<long long int,pair<long long int,long long int>>arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
    }
    sort(arr,arr+n);
    long long int t = 0;
    long long int r,l;
    r=m;l=m;
    long long int time;
    for(long long int i=0;i<n;i++){
        time = arr[i].first - t;
        r = r - time;
        l = l + time;
        t = arr[i].first;
            if(r>arr[i].second.second || l <arr[i].second.first){
                cout<<"NO"<<"\n";
                return;
            }
        l = min(l,arr[i].second.second);
        r = max(r,arr[i].second.first);
    }
    cout<<"YES"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}