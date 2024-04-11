#include<bits/stdc++.h>
using namespace std;
void pre(){}
bool check(int a,int b,int c){
    if(a+b>c){
        return true;
    }
    return false;
}
void solve(){
    long long int n;cin>>n;
    long long int ans = 0;
    set<vector<int>>s;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int k = i^j;
            if(check(i,j,k) && check(i,k,j) && check(k,j,i) && k<=n){
                vector<int>v;
                v.push_back(i);
                v.push_back(j);v.push_back(k);
                sort(v.begin(),v.end());
                s.insert(v);
            }
        }
    }
    cout<<s.size()<<"\n";
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