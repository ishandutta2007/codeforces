#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<pair<long double,long long int>>fo;
    stack<pair<long double,long long int>>be;
    for(long long int i=0;i<n;i++){
        fo.push(make_pair(arr[n-i-1]*1.0,1));
    }
    pair<long double,long long int>p;
    while(fo.size()!=0){
        long long int k = fo.top().first;
        p.first = k;
        p.second = 1;
        fo.pop();
        while(fo.size()!=0 && fo.top().first<=(p.first*1.0)/p.second){
            p.second++;
            p.first+=fo.top().first;
            fo.pop();
        }
        p.first = (p.first*1.0)/p.second;
        while(be.size()!=0 && be.top().first>p.first){
            p.first = p.first*p.second + be.top().first*be.top().second;
            p.second = be.top().second+p.second;
            p.first = (p.first*1.0)/p.second;
            be.pop();
        }
        be.push(p);
    }
    while(be.size()!=0){
        fo.push(be.top());
        be.pop();
    }
    while(fo.size()!=0){
        for(long long int i=0;i<fo.top().second;i++){
            cout<<setprecision(11)<<fo.top().first<<"\n";
        }
        fo.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}