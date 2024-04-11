#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int a,b,x,y;
    cin>>a>>b>>x>>y;
    //a--;b--;
    x++;y++;
    long long int ans = (a-x)*(b-y);
    ans=max(ans,(a-x)*(b));
    ans=max(ans,(b-y)*(a));
    ans=max(ans,(y-1)*(a));
    ans=max(ans,(b)*(x-1));
    cout<<ans<<"\n";
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