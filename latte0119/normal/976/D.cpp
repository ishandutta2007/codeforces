#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

vpint ans;

void solve(vint D,int off){
    if(D.size()==0){
        return;
    }
    if(D.size()==1){
        for(int i=0;i<=D[0];i++){
            for(int j=i+1;j<=D[0];j++){
                ans.eb(i+off,j+off);
            }
        }
        return;
    }

    vint DD;
    for(int i=1;i+1<D.size();i++)DD.pb(D[i]-D[0]);
    solve(DD,off+D[0]);

    int num;
    if(DD.size())num=DD.back()+1;
    else num=1;

    rep(i,D[0]){
        for(int j=i+1;j<=D.back();j++){
            ans.eb(i+off,j+off);
        }
    }
}


signed main(){
    int N;scanf("%lld",&N);
    vint D(N);rep(i,N)scanf("%lld",&D[i]);
    solve(D,0);

    printf("%lld\n",(int)ans.size());
    for(auto &p:ans)printf("%lld %lld\n",p.fi+1,p.se+1);
    return 0;
}