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

int N,W,H;

vint v[222222],hh[222222];

pint ei[111111],ans[111111];
signed main(){
    scanf("%lld%lld%lld",&N,&W,&H);

    vector<tuple<int,int,int,int>>latte;
    rep(i,N){
        int g,p,t;
        scanf("%lld%lld%lld",&g,&p,&t);
        latte.pb(make_tuple(p,g,t,i));
        if(g==1)ei[i]={p,H};
        else ei[i]={W,p};
    }

    sort(all(latte));
    for(auto &w:latte){
        int tmp=get<0>(w)-get<2>(w)+100000;
        if(get<1>(w)==1)v[tmp].pb(get<3>(w));
        else hh[tmp].pb(get<3>(w));
    }

    deque<int>h;
    for(int i=0;i<222222;i++){
        vpint hoge;
        for(auto &w:hh[i])h.pb(w);
        for(auto &w:h)hoge.pb(ei[w]);
        for(auto &w:v[i]){
            if(h.size()){
                int tmp=h.back();
                h.pop_back();
                ans[tmp]=ei[w];
                h.push_front(w);
            }
            else{
                ans[w]=ei[w];
            }
        }

        for(int j=0;j<h.size();j++){
            ans[h[j]]=hoge[j];
        }
        h.clear();
    }

    rep(i,N)printf("%lld %lld\n",ans[i].fi,ans[i].se);
    return 0;
}