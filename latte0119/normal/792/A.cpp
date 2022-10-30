#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int n;
int a[222222];

signed main(){
    cin>>n;
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    int mi=LLONG_MAX;
    rep(i,n-1)chmin(mi,a[i+1]-a[i]);
    int cnt=0;
    rep(i,n-1)if(mi==a[i+1]-a[i])cnt++;
    cout<<mi<<" "<<cnt<<endl;
    return 0;
}