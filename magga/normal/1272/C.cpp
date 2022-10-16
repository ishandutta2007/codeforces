#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,k;
    cin>>n>>k;
    char d;
    set<char>se;
    string s;cin>>s;
    for(long long int i=0;i<k;i++){
        cin>>d;
        se.insert(d);
    } 
    long long int ans=0;
    long long int last = -1;
    for(long long int i=0;i<n;i++){
        if(se.find(s[i])==se.end()){
            ans+=((i-last-1)*(i-last))/2;
            last=i;
        }
    }
    ans+=((n-last-1)*(n-last))/2;
    cout<<ans<<"\n";
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