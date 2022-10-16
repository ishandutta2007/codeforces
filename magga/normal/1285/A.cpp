#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    long long int l=0,r=0;
    string s;cin>>s;
    for(long long int i=0;i<n;i++){
        if(s[i]=='L'){
            l++;
        }else{
            r++;
        }
    }
    cout<<l+r+1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}