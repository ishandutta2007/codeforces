#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int arr[501];
bool check(long long int i,long long int r){
    vector<int>v;
    for(int j=i;j<=r;j++){
        v.push_back(arr[j]);
    }
    int uu = 10000;
    for(auto i:v){
        uu=min(uu,i);
    }
    while(v.size()>1){
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==uu && v[i+1]!=uu){
                return false;
            }else if(v[i]==uu){
                v[i]++;
                v.erase(v.begin()+i+1);
            }
        }
        uu++;
    }
    return true;
}
void solve(){
    long long int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=i;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(check(i,j)){
                dp[j+1]=min(dp[j+1],dp[i]+1);
            }
        }
    }
    cout<<dp[n]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //Scin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}