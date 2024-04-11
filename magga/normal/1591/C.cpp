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
// Please write the recurances once :(
void pre(){}
ll calc(vector<ll>a,int k){
    a.push_back(0);
    sort(a.begin(),a.end());
    int n = a.size();
    ll ret = 0;
    ll curr = 2;
    for(int i=n-1;i>=1;i-=k){
        for(int j=0;(j<k)&(i-j>=1);j++){
            ret += curr*(a[i-j] - a[i-j-1]);
        } 
        curr+=2;
    }
    return ret;
}
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll>p,ne;
    ll m = 0;
    ll d;
    for(int i=0;i<n;i++){
        cin>>d;
        m = max(m,abs(d));
        if(d>0){
            p.push_back(abs(d));
        }else{
            ne.push_back(abs(d));
        }
    }
    cout<<calc(p,k) + calc(ne,k) - m <<"\n";
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