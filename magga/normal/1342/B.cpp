#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    string s;
    cin>>s;
    int n = s.size();
    bool flag = false;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            flag=true;
            break;
        }
    }
    if(!flag){
        cout<<s<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        cout<<"10";
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