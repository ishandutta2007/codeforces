#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,a,b;
    cin>>n>>a>>b;
    string s;
    for(int i=0;i<b;i++){
        s+=char(i+'a');
    }
    for(int i=b;i<a;i++){
        s+='a';
    }
    for(int i=0;i<n;i++){
        cout<<s[i%a];
    }
    cout<<"\n";
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