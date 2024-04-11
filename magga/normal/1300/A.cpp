#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int ans =0;
    long long int sum=0;
    long long int d;
    for(long long int i=0;i<n;i++){
        cin>>d;
        sum+=d;
        if(d==0){
            ans++;
            sum+=1;
        }
    }
    if(sum==0){
        cout<<ans+1<<"\n";
    }else{
        cout<<ans<<"\n";
    }
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