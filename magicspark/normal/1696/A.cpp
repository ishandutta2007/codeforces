#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int n,z,mx=0;cin>>n>>z;
        for(int i=1;i<=n;i++){
            int x;cin>>x;mx=max(mx,x|z);
        }
        cout<<mx<<endl;
    }
}