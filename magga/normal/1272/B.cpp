#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    long long int u=0,d=0,l=0,r=0;
    for(char c:s){
        if(c=='U'){u++;}
        if(c=='D'){d++;}
        if(c=='L'){l++;}
        if(c=='R'){r++;}
    }
    u=min(u,d);
    l=min(l,r);
    if(u==0 && l==0){
        cout<<0<<"\n";
        return;
    }
    if(u==0 && l!=0){
        cout<<2<<"\n";
        cout<<"LR"<<"\n";
        return;
    }
    if(u!=0 && l==0){
        cout<<2<<"\n";
        cout<<"UD"<<"\n";
        return;
    }
    cout<<2*(l+u)<<"\n";
    for(long long int i=0;i<u;i++){
        cout<<"U";
    }
    for(long long int i=0;i<l;i++){
        cout<<"L";
    } for(long long int i=0;i<u;i++){
        cout<<"D";
    } for(long long int i=0;i<l;i++){
        cout<<"R";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}