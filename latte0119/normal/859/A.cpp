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

signed main(){
    set<int>s;
    int K;cin>>K;
    rep(i,K){
        int a;cin>>a;
        s.insert(a);
    }

    for(int i=1;s.size()<25;i++)if(s.find(i)==s.end())s.insert(i);

    cout<<(*s.rbegin())-25<<endl;
    return 0;
}