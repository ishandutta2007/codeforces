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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int INF=1001001001;
const int SIZE=200000;
const int SEG=1<<19;

int N,M;
int X[SIZE],T[SIZE],P[SIZE],B[SIZE];
int cnt[SIZE];
vint xs;
set<pint>s;
int mi[SEG*2],put[SEG*2];

void init(){
    fill_n(mi,SEG*2,INF);
    fill_n(put,SEG*2,INF);
}

inline void push(int k){
    chmin(mi[k],put[k]);
    if(k<SEG-1){
        chmin(put[k*2+1],put[k]);
        chmin(put[k*2+2],put[k]);
    }
}

void update(int a,int b,int x,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        chmin(put[k],x);
        push(k);
        return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
    mi[k]=min(mi[k*2+1],mi[k*2+2]);
}

int get(int a,int b,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return INF;
    if(a<=l&&r<=b)return mi[k];
    return min(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
}

signed main(){
    scanf("%lld%lld",&N,&M);
    map<int,int>conv;
    rep(i,N){
        scanf("%lld%lld",&X[i],&T[i]);
        xs.pb(X[i]);
        conv[X[i]]=i;
    }
    rep(i,M){
        scanf("%lld%lld",&P[i],&B[i]);
        xs.pb(P[i]);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)),xs.end());

    init();

    rep(i,N){
        int l=lower_bound(all(xs),X[i])-xs.begin();
        int r=upper_bound(all(xs),X[i]+T[i])-xs.begin();
        update(l,r,X[i]);
    }

    rep(i,M){
        int p=lower_bound(all(xs),P[i])-xs.begin();
        int idx=get(p,p+1);
        if(idx==INF){
            s.insert(pint(P[i],i));
            continue;
        }
        idx=conv[idx];
        cnt[idx]++;
        T[idx]+=B[i];

        set<pint>::iterator it=s.lower_bound(pint(X[idx],-114514));
        while(it!=s.end()&&it->fi<=X[idx]+T[idx]){
            cnt[idx]++;
            T[idx]+=B[it->se];
            s.erase(it++);
        }
        int l=lower_bound(all(xs),X[idx])-xs.begin();
        int r=upper_bound(all(xs),X[idx]+T[idx])-xs.begin();
        update(l,r,X[idx]);
    }
    rep(i,N)printf("%lld %lld\n",cnt[i],T[i]);
    return 0;
}