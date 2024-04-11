#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int u=0,v=0,w=0;
    for(int i=0,a,b,c;i<N;i++){
        cin>>a>>b>>c;
        u+=a,v+=b,w+=c;
    }
    if(u==0&&v==0&&w==0)cout<<"YES\n";
    else cout<<"NO\n";
}