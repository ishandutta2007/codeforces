#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

int N,L,K;

char ans[1111][1111];

signed main(){
    scanf("%lld%lld%lld",&N,&L,&K);

    string s;cin>>s;
    sort(all(s));
    reverse(all(s));
    fill_n(*ans,1111*1111,'@');
    int idx=0;
    rep(i,L){
        for(int j=idx;j<K;j++){
            ans[j][i]=s.back();
            s.pop_back();
        }
        while(ans[idx][i]!=ans[K-1][i])idx++;
    }

    rep(i,N)rep(j,L)if(ans[i][j]=='@'){
        ans[i][j]=s.back();
        s.pop_back();
    }


    rep(i,N){
        rep(j,L){
            cout<<ans[i][j];
        }cout<<endl;
    }
    return 0;
}