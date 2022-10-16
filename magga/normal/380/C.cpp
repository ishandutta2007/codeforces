#include<bits/stdc++.h>
using namespace std;
void pre(){}
const int N = 2e6; 
int n; 
int t[2 * N];
void build() { 
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1],t[i<<1|1]);
}
int query(int l, int r) {
  int res = 1e7;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}
void solve(){
    string s;cin>>s;
    n = s.size()+1;
    t[n]=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='('){
            t[n+i]=t[n+i-1]+1;
        }else{
            t[n+i]=t[n+i-1]-1;
        }
    }
    build();
    int q,a,b;cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        auto ma = query(a-1,b+1);
        //cout<<ma<<"--\n";
        cout<<b-a+1-(t[n+a-1]-ma)-(t[n+b]-ma)<<"\n"; 
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