#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    int t=n,mx=0;
    while(t)mx=max(mx,t%10),t/=10;
    cout<<mx<<"\n";
    while(n){
        int k=0,t=n,p=1;
        while(t)k=k+p*(bool)(t%10),p*=10,t/=10;
        cout<<k<<(char)32;n-=k;
    }
}