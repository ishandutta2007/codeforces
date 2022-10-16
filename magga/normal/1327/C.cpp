#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m,k;cin>>n>>m>>k;
    pair<long long int,long long int> arr[k];
    pair<long long int,long long int> tar[k];
    for(long long int i=0;i<k;i++)
        cin>>arr[i].first>>arr[i].second;
    for(long long int i=0;i<k;i++)
        cin>>tar[i].first>>tar[i].second;
    if(n==1){
        string ans="";
        for(long long int i=0;i<m;i++)
        ans+='L';   
        for(long long int i=0;i<m;i++)
        ans+='R';
        cout<<ans.size()<<"\n";
        cout<<ans<<"\n";
        return;   
    }else if(m==1){
        string ans="";
        for(long long int i=0;i<n;i++)
        ans+='U';   
        for(long long int i=0;i<n;i++)
        ans+='D';
        cout<<ans.size()<<"\n";
        cout<<ans<<"\n";
        return; 
    }
    string ans = "";
    for(long long int i=0;i<n-1;i++)
        ans+='U';    
    for(long long int i=0;i<m-1;i++)
        ans+='L';      
    bool flag = 1;    
    for(long long int i=0;i<n;i++){
        for(long long int i=0;i<m-1;i++){
            if(flag){
                ans+='R';
            }else{
                ans+='L';
            }
        }
        if(i!=n-1){
            ans+='D';
        }
        flag=!flag;
    } 
    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";   
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