#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k,d;cin>>n>>k;
    long long int curr =0;
    long long int arr[k];
    for(long long int i=0;i<k;i++){
        arr[i]=0;
    }
    for(long long int i=0;i<n;i++){
        cin>>d;
        arr[d%k]++;
        while(arr[(curr)%k]>(curr)/k){
            curr++;
        }
        cout<<curr<<"\n";
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