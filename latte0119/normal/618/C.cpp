#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    int n;cin>>n;
    map<int,vpint>m;
    rep(i,n){
        int x,y;cin>>x>>y;
        m[y].pb(pint(x,i));
    }

    each(it,m)sort(all(it->se));

    vpint ps;
    vint is;
    each(it,m){
        vpint &v=it->se;
        int cc=0;
        rep(i,v.size()){
            if(ps.size()==2){
                long long a=ps[1].fi-ps[0].fi,b=ps[1].se-ps[0].se;
                long long c=it->fi-ps[i].fi,d=v[i].fi-ps[i].se;
                if(a*d-b*c==0)continue;
            }
            ps.pb(pint(it->fi,v[i].fi));
            is.pb(v[i].se+1);
            cc++;
            if(ps.size()==3){
                rep(j,3)cout<<is[j]<<" ";cout<<endl;
                return 0;
            }
            if(cc==2)break;
        }
    }
    return 0;
}