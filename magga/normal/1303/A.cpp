#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    string s;
    cin>>s;
    long long int a=0,b=0,c=0;
        for(char j:s){
            if(j=='1'){
                a++;
            }
        }
    while(s[b]!='1' && b<s.size()){
        b++;
    }
    if(b==s.size()){
        cout<<0<<"\n";
        return;
    }
    c=s.size()-1;
    while(s[c]!='1'){
        c--;
    }
    c = s.size()-c-1;
    cout<<s.size()-b-c-a<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}