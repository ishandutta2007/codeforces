#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    long long int n =s.size();
    if(s.substr(n-2)=="po"){
        cout<<"FILIPINO"<<"\n";
    }else if(s.substr(n-4)=="desu" || s.substr(n-4)=="masu"){
        cout<<"JAPANESE"<<"\n";
    }else if(s.substr(n-5)=="mnida"){
        cout<<"KOREAN"<<"\n";
    }
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