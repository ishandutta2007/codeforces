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

void solve(){
    int n;scanf("%lld",&n);
    vint q(n);rep(i,n)scanf("%lld",&q[i]);

    int ma=-1;
    set<int>s;
    rep(i,n)s.insert(i+1);
    vint p(n);
    rep(i,n){
        if(q[i]<ma){
            cout<<-1<<endl;
            return;
        }
        if(q[i]>ma){
            ma=q[i];
            p[i]=q[i];
            s.erase(q[i]);
            continue;
        }
        if(*s.begin()>ma){
            cout<<-1<<endl;
            return;
        }
        p[i]=*s.begin();
        s.erase(s.begin());
    }

    rep(i,n){
        if(i)printf(" ");
        printf("%lld",p[i]);
    }
    puts("");
}

signed main(){
    int t;scanf("%lld",&t);
    while(t--)solve();
    return 0;
}