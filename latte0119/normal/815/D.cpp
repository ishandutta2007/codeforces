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

int N;
vpint evs[555555];
int P,Q,R;
int p[555555],q[555555],r[555555];
signed main(){
    scanf("%lld%lld%lld%lld",&N,&P,&Q,&R);

    rep(i,N){
        scanf("%lld%lld%lld",&p[i],&q[i],&r[i]);
        evs[P].pb({q[i],r[i]});
        evs[p[i]].pb({Q,r[i]});
        evs[p[i]].pb({q[i],R});
    }

    int sum=0;
    set<pint>st;
    st.insert({0,INT_MAX});
    st.insert({INT_MAX,0});

    int ans=0;
    for(int i=P;i>0;i--){
        for(auto &p:evs[i]){
            auto it=st.lower_bound(p);
            if(p.se<=it->se)continue;

            while(true){
                auto q=*it;
                if(q.se>p.se)break;
                it--;
                auto r=*it;
                sum+=(min(p.fi,q.fi)-r.fi)*(p.se-q.se);
                if(q.fi<=p.fi)st.erase(q);
            }
            st.insert(p);
        }
        ans+=sum;
    }
    cout<<P*Q*R-ans<<endl;
    return 0;
}