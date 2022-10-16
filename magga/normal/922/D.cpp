#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int va(string val){
    long long int ans = 0;
    long long int oo = 0;
    for(int i=0;i<val.size();i++){
        if(val[i]=='h'){
            oo++;
        }else{
            ans+=oo;
        }
    }
    return ans;
}
bool comp(string &a,string &b){
    string oo = a+b;
    string op = b+a;
    return (va(oo) > va(op));
}
void solve(){
    long long int n;cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]=='s'){
                arr[i][j]='h';
            }else{
                arr[i][j]='s';
            }
        }
    }
    sort(arr,arr+n,comp);
    string val="";
    for(auto i:arr){
        val+=i;
    }
    cout<<va(val)<<"\n";
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