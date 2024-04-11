#include <bits/stdc++.h>
using namespace std;
void solve(){
    int N,M,temp;
    cin>>N>>M;
    map<int,bool> mp;
    for(int i=0;i<N;i++){
        cin>>temp;
        mp[temp]=true;
    }
    bool found=false;
    for(int i=0;i<M;i++){
        cin>>temp;
        if(mp[temp]){
            if(found)continue;
            else{
                cout<<"YES\n1 "<<temp<<"\n";
                found=true;
            }
        }
    }
    if(!found)cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}