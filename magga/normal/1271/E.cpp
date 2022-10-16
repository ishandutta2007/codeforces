#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int n,k;
long long int pru(long long int aa){
    long long int curr = aa,ret = 0,cu = 1,val = 0;
    while(curr<=n){
        ret+=cu;
        curr*=2;
        curr+=1;
        cu*=2;
        val++;
    }
    ret+=max((long long int)0,n+1-(aa<<val));
    return ret;
}
long long int val(long long int oo){
    long long int bb=0;
    if(oo%2==0) bb+=pru(oo+1);
    bb+=pru(oo);
    return bb;
}
void solve(){
    cin>>n>>k;
    unsigned long long int ans = 0;
    for(long long int i=62;i>=0;i--){
        //cout<<(ans+(long long int)1<<i)<<"\n";
        if(val(ans+((long long int)1<<i))>=k){
            ans+=((long long int)1<<i);
            //cout<<ans<<"\n";
        }
    }
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