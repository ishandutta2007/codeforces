#include<bits/stdc++.h>
using namespace std;
long long int arr[1000001];
unordered_map<int,vector<int>>m;
bool pos[1000001]{0};
bool ans[1000001]{0};
void pre(){}
void solve(){
    long long int n,t,d;cin>>n;
    for(int i=0;i<n;i++){cin>>arr[i];m[arr[i]].push_back(i);}
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>d;
        pos[d-1]=1;
    }
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        if(s.size()<=0 || pos[i] || s.top()!=arr[i]){
            s.push(arr[i]);
            ans[i]=0;
        }else{
            s.pop();
            ans[i]=1;
        }
    }
    if(s.size()>0){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<n;i++){
        if(ans[i]){
            cout<<arr[i]<<" ";
        }else{
            cout<<-1*arr[i]<<" ";
        }
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}