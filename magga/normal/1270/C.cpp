#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,d;cin>>n;
    long long int x=0,s=0;
    for(long long int i=0;i<n;i++){
        cin>>d;
        s+=d;
        x^=d;
    }
    cout<<2<<"\n";
    cout<<x<<" "<<s+x<<"\n";
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