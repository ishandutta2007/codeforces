#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,mx=122690412,ptr=0;
    cin>>n>>k;
    for(int i=0,u,v;i<n;i++){
        cin>>u>>v;
        while(u<k)u+=v;
        if(mx>=u){
            mx=u;
            ptr=i+1;
        }
    }
    cout<<ptr<<"\n";
}