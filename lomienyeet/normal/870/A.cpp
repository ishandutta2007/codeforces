#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[10]={},mini=1e9,mn=1e9,zz=1e9;
    for(int i=0,x;i<n;i++){
        cin>>x;
        mini=min(mini,x);
        arr[x]=x;
    }
    for(int i=0,x;i<m;i++){
        cin>>x;
        mn=min(mn,x);
        if(arr[x])zz=min(zz,x);
    }
    if(mini==mn)cout<<mini<<"\n";
    else if(mini>mn)cout<<min(zz,mn*10+mini)<<"\n";
    else cout<<min(zz,mini*10+mn)<<"\n";
}