#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int a[n];
    long long int b[n];
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(long long int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(long long int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
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