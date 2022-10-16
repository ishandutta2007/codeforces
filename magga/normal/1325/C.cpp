#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,a,b;cin>>n;
    map<pair<long long int,long long int>,long long int>m;
    vector<long long int>arr[n];
    for(long long int i=0;i<n-1;i++){
        cin>>a>>b;
        a--,b--;
        m[{min(a,b),max(a,b)}]=i;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    long long int ans[n-1];
    for(long long int i=0;i<n-1;i++) ans[i]=-1;
    long long int flag = -1;
    for(long long int i=0;i<n;i++){
        if(arr[i].size()>2){
            flag=i;
            break;
        }
    }
    if(flag == -1){
        for(long long int i=0;i<n-1;i++){
            cout<<i<<"\n";
        }
        return;
    }
    ans[m[{min(flag,arr[flag][0]),max(flag,arr[flag][0])}]]=0;
    ans[m[{min(flag,arr[flag][1]),max(flag,arr[flag][1])}]]=1;
    ans[m[{min(flag,arr[flag][2]),max(flag,arr[flag][2])}]]=2;
    long long int val = 3;
    for(long long int i:ans){
        if(i==-1){
            cout<<val<<"\n";
            val++;
        }
        else{
            cout<<i<<"\n";
        }
    }
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