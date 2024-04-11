#include<bits/stdc++.h>
using namespace std;
void pre(){}
const int N = 1e5;
int n;
pair<long long int,int> t[2 * N];
pair<long long int,int> b[2 * N];
pair<long long int,int> combine(pair<long long int,int>a,pair<long long int,int>b){
    if(a.first>b.first){
        return a;
    }else{
        return b;
    }
}
pair<long long int,int> combine2(pair<long long int,int>a,pair<long long int,int>b){
    if(a.first>b.first){
        return b;
    }else{
        return a;
    }
}
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1],t[i<<1|1]);
  for (int i = n - 1; i > 0; --i) b[i] = combine2(b[i<<1],b[i<<1|1]);
}
pair<long long int,int> query(int l, int r) { 
  pair<long long int,int> res = {-1e10,0};
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = combine(res,t[l++]);
    if (r&1) res = combine(t[--r],res);
  }
  return res;
}
pair<long long int,int> query2(int l, int r) { 
  pair<long long int,int> res = {1e10,0};
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = combine2(res,b[l++]);
    if (r&1) res = combine2(b[--r],res);
  }
  return res;
}
long long int arr[100001];
long long int ans = 0;
void rec(int l,int r){
    if(r<=l){
        return;
    }
    auto i = query(l,r+1);
    auto j = query2(i.second,r+1);
    //cout<<j.first<<"\n";
    long long int moo = i.first-j.first;
    long long int uu = 1;
    long long int blu = 0;
    while(moo>uu-1){
        uu*=2;
        blu++;
    }
    ans=max(ans,blu);
    rec(i.second+1,r);
    rec(l,i.second-1);
}
void solve(){
    cin>>n;
    ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        t[n+i]={arr[i],i};
        b[n+i]={arr[i],i};
    }
    build();
    rec(0,n-1);
    cout<<ans<<"\n";
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