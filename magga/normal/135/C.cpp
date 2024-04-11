#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    string s;cin>>s;
    int n = s.size()-2;
    int a=0,b=0,c=0;
    for(auto i:s){
        if(i=='1')a++;
        else if(i=='0')b++;
        else c++;
    }
    set<string>s1;
    if(a+c>=(n+1)/2+2){
        s1.insert("11");
    }
    if(b+c>=(n/2)+2){
        s1.insert("00");
    }
    if(a<=(n+1)/2+1 && b<=(n/2)+1){
        if(s[n+1]=='1'){
            s1.insert("01");
        }else if(s[n+1]=='0'){
            s1.insert("10");
        }
    }
    if(s[n+1]=='?' && a==(n+1)/2+1){
        s1.insert("10");
    }else if(s[n+1]=='?' && b==(n/2)+1){
        s1.insert("01");
    }else if(a<(n+1)/2+1 && b<(n/2)+1 && s[n+1]=='?'){
        s1.insert("10");
        s1.insert("01");
    }
    for(auto i:s1){
        cout<<i<<"\n";
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