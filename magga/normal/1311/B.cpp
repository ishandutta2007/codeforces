#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m,d;
    cin>>n>>m;
    long long int arr[n];
    long long int ans[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        ans[i]=arr[i];
    }    
    sort(arr,arr+n);
    set<long long int>s;
    for(long long int i=0;i<m;i++){cin>>d;s.insert(d);}
    for(long long int i=0;i<n;i++){
        for(long long int j:s){
            if(ans[j-1]>ans[j]){
                d=ans[j-1];
                ans[j-1]=ans[j];
                ans[j]=d;
            }
        }
    }
    for(long long int i=0;i<n;i++){
        if(ans[i]!=arr[i]){
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
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}