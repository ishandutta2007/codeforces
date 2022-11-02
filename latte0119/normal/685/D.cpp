#include<bits/stdc++.h>
using namespace std;

#define int long long
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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}


int N,K;
int x[100000],y[100000];

int ans[111111];

void execute(vpint &ev,int w){
    int cnt=0;
    for(int i=0;i+1<ev.size();i++){
        int h=ev[i+1].first-ev[i].first;
        cnt+=ev[i].second;
        ans[cnt]+=h*w;
    }
}

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld%lld",&x[i],&y[i]);

    map<int,vpint>ps;
    rep(i,N){
        ps[x[i]-K].pb(pint(y[i]-K,1));
        ps[x[i]-K].pb(pint(y[i],-1));
        ps[x[i]].pb(pint(y[i]-K,-1));
        ps[x[i]].pb(pint(y[i],1));
    }

    map<int,vpint>::iterator it,jt;
    it=jt=ps.begin();
    jt++;

    vpint ev;

    for(;jt!=ps.end();it++,jt++){
        int w=jt->first-it->first;
        vpint &v=it->second;
        sort(all(v));
        vpint ev_;
        int i=0,j=0;
        while(i<ev.size()||j<v.size()){
            if(i<ev.size()&&(j==v.size()||ev[i].first<=v[j].first)){
                ev_.pb(ev[i++]);
            }
            else{
                if(ev_.size()&&ev_.back().first==v[j].first)ev_.back().second+=v[j++].second;
                else ev_.pb(v[j++]);
            }
            if(ev_.back().second==0)ev_.pop_back();
        }
        ev=ev_;
        execute(ev,w);
    }


    for(int i=1;i<=N;i++)printf("%lld ",ans[i]);
    return 0;
}