#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int r,c;cin>>r>>c;
    if(r==1 && c==1){
        cout<<0<<"\n";
        return;
    }
    if(r==1){
        for(long long int i=1;i<r+1;i++){
            for(long long int j=r+1;j<c+r+1;j++){
                cout<<i*j<<" ";
            }
            cout<<"\n";
        }
        return;
    } 
    if(c==1){
        for(long long int i=1;i<r+1;i++){
            cout<<i+1;
            cout<<"\n";
        }
        return;
    } 
    for(long long int i=1;i<r+1;i++){
        for(long long int j=r+1;j<c+r+1;j++){
            cout<<i*j<<" ";
        }
        cout<<"\n";
    }
    return;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1 ;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}