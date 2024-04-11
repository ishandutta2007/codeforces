#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int x,y;cin>>y>>x;x--;
    if(x>0 && y-x>=0 && (y-x)%2==0){
        cout<<"Yes"<<"\n";
    }else if(x==0 && y==0){        
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}