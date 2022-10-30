#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int W,H,N;
signed main(){
    scanf("%lld%lld%lld",&W,&H,&N);
    set<int>w,h;
    multiset<int>mw,mh;

    w.insert(0);w.insert(W);h.insert(0);h.insert(H);
    mw.insert(W);mh.insert(H);

    rep(i,N){
        char c;
        int d;
        scanf(" %c%lld",&c,&d);
        if(c=='H'){
            auto it=h.lower_bound(d);
            auto it2=it;
            it2--;
            mh.erase(mh.find(*it-*it2));
            mh.insert(d-*it2);
            mh.insert(*it-d);
            h.insert(d);
        }
        else{
            auto it=w.lower_bound(d);
            auto it2=it;
            it2--;
            mw.erase(mw.find(*it-*it2));
            mw.insert(d-*it2);
            mw.insert(*it-d);
            w.insert(d);
        }
        printf("%lld\n",(*mh.rbegin())*(*mw.rbegin()));
    }
}