#include<bits/stdc++.h>
using namespace std;
void pre(){}
bool check(unsigned long long int a,unsigned long long int b){
    b=(b&a);
    return a==b;
}
void solve(){
    long long int n;cin>>n;
    unsigned long long int arr[n];
    long long int brr[n];
    map<unsigned long long int,int>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
   // cout<<check(2,3)<<"\n";
    for(int i=0;i<n;i++) cin>>brr[i];
    long long int ans = 0;
    set<unsigned long long int>s;
    for(auto i:m){
        if(i.second<2){
            continue;
        }
        for(int p=0;p<n;p++){
            if(check(arr[p],i.first) && s.find(p)==s.end()){
                ans+=brr[p];
                s.insert(p);
            }
        }
    }
    cout<<ans<<"\n";
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