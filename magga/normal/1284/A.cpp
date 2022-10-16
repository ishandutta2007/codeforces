#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,m,q,d;cin>>n>>m;
    string arr[n];
    string brr[m];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(long long int i=0;i<m;i++){
        cin>>brr[i];
    }
    cin>>q;
    for(long long int i=0;i<q;i++){
        cin>>d;
        d--;
        cout<<arr[d%n]+brr[d%m]<<"\n";
    }
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