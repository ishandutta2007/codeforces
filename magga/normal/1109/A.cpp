#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,d;cin>>n;
    map<long long int,int>odd,even;
    long long int ans = 0;
    long long int oo = 0;
    odd[0]++;
    for(int i=0;i<n;i++){
        cin>>d;oo^=d;
        //0cout<<oo<<"\n";
        if(i%2==0){
            ans+=even[oo];
            even[oo]++;
        }else{
            ans+=odd[oo];
            odd[oo]++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //scin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}