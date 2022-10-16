#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m,d;
    cin>>n>>m;
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        cin>>d;
        sum+=d;
    }
    cout<<min(sum,m)<<"\n";
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