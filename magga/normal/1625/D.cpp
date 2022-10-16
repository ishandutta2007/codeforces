#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<int,int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}

pair<int,pair<pii,pii>> dnc2(vector<pii> &a,vector<pii> &b,ll k,ll i){
    int n = a.size();
    int m = b.size();
    if(n==0 && m==0) return {0,{{0,0},{0,0}}};
    else if(m==0) return {1,{a[0],{0,0}}};
    else if(n==0) return {1,{b[0],{0,0}}};
    else if(i==-1) return {2,{a[0],b[0]}};
    vector<pii>arr[2];
    for(int j=0;j<n;j++){
        if(a[j].F&(1<<i)){
            arr[1].push_back(a[j]);
        }else{
            arr[0].push_back(a[j]);
        }
    }
    vector<pii>brr[2];
    for(int j=0;j<m;j++){
        if(b[j].F&(1<<i)){
            brr[1].push_back(b[j]);
        }else{
            brr[0].push_back(b[j]);
        }
    }
    if(k&(1<<i)){
        auto ans1 =  dnc2(arr[0],brr[1],k,i-1);
        auto ans2 =  dnc2(arr[1],brr[0],k,i-1);  
        if(ans1.F > ans2.F) return ans1;
        else return ans2;  
    }else{
        if(arr[0].size()>0 && brr[1].size()>0){
            return {2,{arr[0][0],brr[1][0]}};
        }else if(arr[1].size()>0 && brr[0].size()>0){
            return {2,{arr[1][0],brr[0][0]}};
        }
        auto ans1 =  dnc2(arr[0],brr[0],k,i-1);
        auto ans2 =  dnc2(arr[1],brr[1],k,i-1);
        if(ans1.F > ans2.F) return ans1;
        else return ans2;  
    }
}
vector<pii>dnc(vector<pii> &a,ll k,ll i){
    int n = a.size();
    if(i==-1 || n==0 || n==1){
        auto a1 = a;
        return a1;
    }
    vector<pii>arr[2];
    for(int j=0;j<n;j++){
        if(a[j].F&(1<<i)){
            arr[1].push_back(a[j]);
        }else{
            arr[0].push_back(a[j]);
        }
    }
    if(k&(1<<i)){
        auto ans1 =  dnc2(arr[0],arr[1],k,i-1);
        vector<pii>ret;
        if(ans1.F>=1) ret.push_back(ans1.S.F);
        if(ans1.F>=2) ret.push_back(ans1.S.S);
        return ret;
    }else{
        arr[0] = dnc(arr[0],k,i-1);
        arr[1] = dnc(arr[1],k,i-1);
        for(auto i:arr[0]) arr[1].push_back(i);
        return arr[1];
    }
}
void solve(){
    ll n,k;cin>>n>>k;
    vector<pii>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].F;
        arr[i].S = i+1;
    }
    auto ans = dnc(arr,k,29);
    if(ans.size()<2){
        cout<<"-1\n";
        return;
    } 
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.S<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}