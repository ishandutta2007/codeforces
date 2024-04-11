#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int a,b,c,k=0;cin>>a>>b;
    c=b+1;
    while(c>=10){
        c/=10;
        k++;
    }
    cout<<k*a<<"\n";
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