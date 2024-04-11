#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int B=500;
int N,Q;
int A[222222];

int inv;

struct event{
    int l,r,h;
    int id,k;
    event(int l,int r,int h,int id,int k):l(l),r(r),h(h),id(id),k(k){}
};
bool operator<(const event &a,const event &b){
    return a.h<b.h;
}

vector<vint>makeList(vint &ps){
    vector<int>pos(N);
    vector<int>r(N);
    for(int i=0;i<N;i++){
        if(i)pos[i]=pos[i-1];
        if(ps[pos[i]+1]==i)pos[i]++;
        r[A[i]]=i;
    }

    vector<vint>res(ps.size());
    for(int i=0;i<N;i++)res[pos[r[i]]].pb(i);
    return res;
}

void solve(vpint qs){
    vector<int>ps;
    ps.pb(0);ps.pb(N);
    rep(i,qs.size()){
        ps.pb(qs[i].fi);
        ps.pb(qs[i].fi+1);
        ps.pb(qs[i].se);
        ps.pb(qs[i].se+1);
    }
    sort(all(ps));ps.erase(unique(all(ps)),ps.end());
    
    vector<int>AA(N);
    vector<vint>v=makeList(ps);
    vector<int>itr(ps.size());

    rep(i,ps.size())sort(all(v[i]));

    rep(i,N)AA[i]=A[i];

    vector<int>rev(qs.size());
    vector<int>kk(qs.size());
    vector<event>es;
    rep(i,qs.size()){
        int l=lower_bound(all(ps),qs[i].fi+1)-ps.begin();
        int r=lower_bound(all(ps),qs[i].se)-ps.begin();

        int x=min(AA[qs[i].fi],AA[qs[i].se]);
        int y=max(AA[qs[i].fi],AA[qs[i].se]);

        es.pb(event(l,r,x+1,i,-1));
        es.pb(event(l,r,y,i,1));

        if(AA[qs[i].fi]<AA[qs[i].se])kk[i]=1;
        else if(AA[qs[i].fi]>AA[qs[i].se]) kk[i]=-1;
        else kk[i]=0;

        for(int j=l;j<r;j++){
            int bef=(x<A[ps[j]]&&A[ps[j]]<y?-1:1);
            int aft=(x<AA[ps[j]]&&AA[ps[j]]<y?-1:1);
            if(bef*aft==1)continue;
            rev[i]+=bef*kk[i]*2;
        }
        if(qs[i].fi!=qs[i].se)swap(AA[qs[i].fi],AA[qs[i].se]);
    }

    vector<int>cnt(qs.size());
    sort(all(es));
    for(auto &e:es){
        int tmp=0;
        for(int i=e.l;i<e.r;i++){
            if(i<0||i>=ps.size())for(;;);
            while(itr[i]<v[i].size()&&v[i][itr[i]]<e.h)itr[i]++;
            tmp+=itr[i];
        }
        cnt[e.id]+=e.k*tmp;
    }
    
    for(int i=0;i<qs.size();i++){
        inv+=kk[i]*cnt[i]*2;
        inv+=rev[i];
        inv+=kk[i];
        printf("%lld\n",inv);
    }
    rep(i,N)A[i]=AA[i];
}

signed main(){
    scanf("%lld%lld",&N,&Q);
    rep(i,N)A[i]=i;

    vector<vpint>qs((Q+B-1)/B);
    rep(i,Q){
        int a,b;scanf("%lld%lld",&a,&b);
        if(a>b)swap(a,b);
        a--;b--;
        qs[i/B].pb({a,b});
    }
    rep(i,qs.size()){
        solve(qs[i]);
    }
    return 0;
}