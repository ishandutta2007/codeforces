#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

const long long int N = 2e5;
long long int n;
long long int t[2*N];
long long int combine(long long int a,long long int b){
    return a+b;
}
void build(){
    for(long long int i=n-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,long long int value){
    for(t[p+=n]=value;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
long long int query(long long int l,long long int r){
    long long int ret = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(t[--r],ret);
    }
    return ret;
}

// Please write the recurances once :(
void pre(){}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) t[n+i]=1;
    build();
    string s,t;cin>>s>>t;
    vector<int>dp[26];
    string k = s;
    sort(k.begin(),k.end());
    if(k>t){
        cout<<-1<<"\n";
        return;
    }
    for(int i=0;i<26;i++) dp[i].push_back(1e9);
    for(int i = n-1;i>=0;i--){
        dp[s[i]-'a'].push_back(i);
    }
    ll ans = 1e15;
    ll curr = 0;
    for(int i=0;i<n;i++){
        int pos = 1e9;
        int con = -1;
        for(int j=t[i]-'a'-1;j>=0;j--){
            if(dp[j].back()<pos){
                pos = dp[j].back();
                con = j;
            }
        }
        if(con!=-1)
            ans = min(ans,curr + query(0,pos));
        if(dp[t[i]-'a'].back()==1e9) break;
        curr = curr + query(0,dp[t[i]-'a'].back());
        modify(dp[t[i]-'a'].back(),0);
        dp[t[i]-'a'].pop_back();

    }
    if(ans==1e15) ans=-1;
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