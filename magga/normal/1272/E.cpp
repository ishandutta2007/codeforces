#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int inf = 2e10;
void solve(){
    long long int n,d;cin>>n;
    vector<long long int> g[n];
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        if(i-arr[i]>=0) g[i-arr[i]].push_back(i);
        if(i+arr[i]<n)  g[i+arr[i]].push_back(i);
    }
    long long int odd[n];
    long long int even[n];
    bool vis1[n];
    bool vis2[n];
    queue<int>q1,q2;
    for(long long int i=0;i<n;i++){
        vis1[i]=0;
        vis2[i]=0;
        if(arr[i]%2==0){
            even[i]=0;
            vis1[i]=1;
            odd[i]=-1;
            q1.push(i);
        }
        else{
            vis2[i]=1;
            q2.push(i);
            odd[i]=0;
            even[i]=-1;
        }
    }
    while(q1.size()>0){
        int a = q1.front();
        q1.pop();
        for(auto i:g[a]){
            if(!vis1[i]){
                q1.push(i);
                vis1[i]=1;
                even[i]=even[a]+1;
            }
        }
    }
    while(q2.size()>0){
        int a = q2.front();
        q2.pop();
        for(auto i:g[a]){
            if(!vis2[i]){
                q2.push(i);
                vis2[i]=1;
                odd[i]=odd[a]+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            cout<<odd[i]<<" ";
        }else{
            cout<<even[i]<<" ";
        }
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