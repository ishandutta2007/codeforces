#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int a[n];
    long long int b[n];
    int a1=n,a2=n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            a1=min(a1,i);
        }
        if(a[i]==-1){
            a2=min(a2,i);
        }
    }
    for(int i=0;i<n;i++)
        cin>>b[i];

    for(int i=0;i<n;i++){
        if(a[i]<b[i] && a1>=i){
            cout<<"NO"<<"\n";
            return;
        }
        if(a[i]>b[i] && a2>=i){
            cout<<"NO"<<"\n";
            return;
        }
    } 
    cout<<"YES"<<"\n";   
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