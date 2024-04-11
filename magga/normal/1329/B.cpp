#include<bits/stdc++.h>
using namespace std;
long long int bo[63];
void pre(){
    bo[0]=1;
    for(long long int i=1;i<63;i++){
        bo[i]=2*bo[i-1];
    }
}
void solve(){
    long long int d,m;cin>>d>>m;
    long long int cach[64];
    cach[0]=1;
    int i = 1;
    while(bo[i]<=d){
        cach[i]=min(bo[i],d-bo[i]+1);
        //cout<<i<<" "<<cach[i]<<"\n";
        i++;
    }
    long long int ans = 1;
    for(long long int j=0;j<i;j++){
        ans*=(cach[j]+1)%m;
        ans%=m;
    }
    cout<<(ans-1+m)%m<<"\n";
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