#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int a =0;
void solve(){
    long long int n,a,b,sum,ans;;cin>>n>>a>>b;
    sum=(n+1)/2;
    if(sum%a==0) ans=(sum/a-1)*(a+b)+a;
    else ans=(sum/a)*(a+b)+sum%a;
    if(ans<n) cout<<n<<"\n";
    else cout<<ans<<"\n";
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