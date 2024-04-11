#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long int t,p,c,r,a,b,c1,c2;cin>>t>>p>>c>>r;
    a=min(t,p);
    b=max(t,p);
    c1=c+r;
    c2=c-r;
    long long int ans=0;
    if(c2>b){
        ans=b-a;
    }else if(c1<a){
        ans=b-a;
    }else{
        ans=(max(c2,a)-a)+(b-min(b,c1));
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