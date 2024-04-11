#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    string s;cin>>s;
    bool arr[n];
    long long int count=0;
    for(long long int i=0;i<n;i++){
        if(s[i]=='W'){
            count++;
            arr[i]=1;
        }else{
            arr[i]=0;
        }
    }
    bool flag = false;
    if(count%2==0){
        flag = true;
    }else if(n%2==0){
        cout<<-1<<"\n";
        return;
    }
    vector<long long int>v;
    for(long long int i=0;i<n-1;i++){
        if(arr[i]==flag){
            v.push_back(i);
            arr[i+1]=!arr[i+1];
        }
    }
    cout<<v.size()<<"\n";
    if(v.size()!=0){
        for(long long int i=0;i<v.size();i++){
            cout<<v[i]+1<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
   // cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}