#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int beck = n;
    long long int uu = 4;
    int b = 0;
    while(uu<=n){
        b+=2;
        uu*=4;
    }
    long long int ans = ((long long int )1)<<(b);
    n-=ans;
    n/=3;
    //cout<<b<<"\n";
    long long int first = ans+n;
    long long int second = ((long long int )1)<<b+1;
    for(int i=b;i>1;i-=2){
        long long int oo = ((long long int )1)<<(i-2);
        if(n/oo==0){
            continue;
        }else if(n/oo==1){
            second+=(((long long int )1)<<(i-1));
        }else if(n/oo==2){
            
             second+=(((long long int )1)<<(i-1))+(((long long int )1)<<(i-2));
        }else{
            second+=(((long long int )1)<<(i-2));
            //second+=(1<<(i-1))+(1<<(i-2));
        }
        n%=oo;
    }
    long long int third = first^second;
    if(beck%3==1){
        cout<<first<<"\n";
    }else if(beck%3==2){
        cout<<second<<"\n";
    }else{
        cout<<third<<"\n";
    }
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