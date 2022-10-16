#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int a,c,k;
    cin>>a>>c>>k;
    long long int r = min(a,c);
    long long int b = max(a,c);
    if(b%r==0 && b/r<=k){
        cout<<"OBEY"<<"\n";
        return;
    }else if((b-1-__gcd(r,b))/r<k-1){
        cout<<"OBEY"<<"\n";
        return;
    }
    cout<<"REBEL"<<"\n";
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