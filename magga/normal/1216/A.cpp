#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,ans=0,aa=0,ab=0;cin>>n;
    string s;cin>>s;
    for(long long int i=0;i<n;i+=2){
        if(s[i]=='a'){
            if(s[i+1]!='b'){
                s[i+1]='b';
                ans++;
            }
        }
        if(s[i]=='b'){
            if(s[i+1]!='a'){
                s[i+1]='a';
                ans++;
            }
        }
    }
    cout<<ans<<"\n"<<s<<"\n";
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