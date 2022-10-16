#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    unsigned long long int n,k,val=1,beck;cin>>n>>k;n++;
    for(unsigned long long int i=2;i<=k;i++){
        beck=val;
        auto p = i/__gcd(val,i);
        val=(val*p);
        if(val>n || val/p!=beck){
            cout<<"No"<<"\n";
            return;
        }
    }
    if((n)%val==0){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
    }
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