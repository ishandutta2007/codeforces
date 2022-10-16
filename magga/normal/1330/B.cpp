#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int m = 0;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        m=max(arr[i],m);
    }
    long long int a = m,b=n-m;
    set<pair<int,int>>v;
    set<long long int>s1,s2,s3,s4;
    for(long long int i=1;i<=a;i++){
        s1.insert(i);
        s4.insert(i);
    }
    for(long long int i=1;i<=b;i++){
        s2.insert(i);
        s3.insert(i);
    }
    for(long long int i=0;i<n;i++){
        if(s1.size()!=0){
            s1.erase(arr[i]);
        }else{
            s3.erase(arr[i]);
        }
    }
    for(long long int i=0;i<n;i++){
        if(s2.size()!=0){
            s2.erase(arr[i]);
        }else{
            s4.erase(arr[i]);
        }
    }
    if(s4.size()==0){
        v.insert({b,a});
    }
    if(s3.size()==0){
        v.insert({a,b});
    }
    cout<<v.size()<<"\n";
    for(auto i:v){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}