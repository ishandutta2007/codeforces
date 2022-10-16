#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    string s;cin>>s;
    n=s.size();
    vector<long long int>v;
    long long int ans =0;
    for(long long int i=0;i<n-2;i++){
        if(i<n-4 && s.substr(i,5)=="twone"){
            v.push_back(i+2);
            i+=3;
        }else
        if(s.substr(i,3)=="one"){
            v.push_back(i+1);
            i+=2;
        }else 
        if(s.substr(i,3)=="two"){
            v.push_back(i+1);
            i+=2;
        }
    }
    cout<<v.size()<<"\n";
    for(long long int i:v){
        cout<<i+1<<" ";
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