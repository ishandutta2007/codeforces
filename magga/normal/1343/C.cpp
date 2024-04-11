#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    long long int pos = 0;
    int pi = -1;
    long long int nev = 0;
    int pn = -1;
    long long int dp[n+1];
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            if(pn+1==pi){
                pos=max(pos,nev+arr[i]);
            }else if(pn+1>pi){
                pos=nev+arr[i];
                pi=pn+1;
            }
        }else{
            if(pi+1==pn){
                nev=max(nev,pos+arr[i]);
            }else if(pi+1>pn){
                nev=pos+arr[i];
                pn=pi+1;
            }
        }
    } 
    if(pi==pn){
        cout<<max(nev,pos)<<"\n";
    }else if(pi>pn){
        cout<<pos<<"\n";
    }else{
        cout<<nev<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<": ";
       	solve();
    }   
}