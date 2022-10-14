#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,k,a[N];
int main(){
    ios::sync_with_stdio(0);
    for(cin>>t;t--;){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(k==1){
            cout<<(n-1)/2<<"\n";
        }else{
            int t=0;
            for(int i=2;i<n;i++)
                t+=a[i-1]+a[i+1]<a[i];
            cout<<t<<"\n";
        }
    }
}