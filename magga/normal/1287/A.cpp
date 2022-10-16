#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    string s;cin>>s;
    s+='A';
    long long int ans =0;
    long long int curr =0;
    bool flag = false;
    for(long long int i=0;i<=n;i++){
        if(s[i]=='P' && flag){
            curr++;
        }else if(s[i]=='A'){
            flag = true;
            if(curr>ans){
                ans=curr;
            }
            curr=0;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}