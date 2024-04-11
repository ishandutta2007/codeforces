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

int N;
signed main(){
    cin>>N;
    map<int,int>cnt;
    rep(i,N){
        int a;cin>>a;
        cnt[a]++;
    }

    int ma=0;
    for(auto &p:cnt)chmax(ma,p.se);
    cout<<ma<<endl;
    return 0;
}