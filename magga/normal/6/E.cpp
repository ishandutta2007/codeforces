#include<bits/stdc++.h>
using namespace std;
void pre(){}
const int N = 1e5; 
int n; 
int t[2 * N];
int t2[2 * N];
void build() { 
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1],t[i<<1|1]);
  for (int i = n - 1; i > 0; --i) t2[i] = max(t2[i<<1],t2[i<<1|1]);
}
int query1(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(t2[l++],res);
    if (r&1) res = max(t2[--r],res);
  }
  return res;
}
int query2(int l, int r) {  // sum on interval [l, r)
  int res = 1e7;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(t[l++],res);
    if (r&1) res = min(t[--r],res);
  }
  return res;
}
int query(int l,int r){
    r++;
    return query1(l,r)-query2(l,r);
}
void solve(){
    long long int k;cin>>n>>k;
    for(long long int i=0;i<n;i++){
        cin>>t[n+i];
        t2[n+i]=t[n+i];
    }
    build();
    vector<long long int>v;
    long long int ans = 0;
    long long int start,end,mid,val;
    for(long long int i=0;i<n;i++){
        start=i;
        end=n-1;
        val=0;
        while(start<=end){
            mid=(start+end+1)/2;
            if(query(i,mid)<=k){
                val=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        if(val-i+1>ans){
            v.clear();
            ans=val-i+1;
            v.push_back(i);
        }else if(val-i+1==ans){
            v.push_back(i);
        }
    }
    cout<<ans<<" "<<v.size()<<"\n";
    for(auto i:v){
        cout<<i+1<<" "<<i+ans<<"\n";
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