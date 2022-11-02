#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int MN=100000;


struct RMQ{
    int N;
    vint dat;
    void init(int n){
        for(N=1;N<n;N<<=1);
        dat.assign(N*2,-1);
    }
    void update(int k,int x){
        k+=N-1;
        dat[k]=max(dat[k],x);
        while(k){
            k=(k-1)/2;
            dat[k]=max(dat[k*2+1],dat[k*2+1]);
        }
    }
    int get(int a,int b){return get(a,b,0,0,N);}
    int get(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return -1;
        if(a<=l&&r<=b)return dat[k];
        return max(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
    }
};

int N;
int x[MN],y[MN];
int w[MN];


int cnt[MN*5];


vector<pint>ans;
vector<vector<pint> >lis;
RMQ paint;
signed main(){
    scanf("%d",&N);
    rep(i,N)scanf("%d%d",&x[i],&y[i]);
    rep(i,N)scanf("%d",&w[i]);

    lis.resize(202020);
    paint.init(202020);
    rep(i,N){
        lis[y[i]-x[i]+100000].pb(pint(y[i],x[i]));
    }

    rep(i,lis.size())sort(lis[i].begin(),lis[i].end());
    rep(i,N){
        int idx=w[i]+100000;
        if(lis[idx].size()==cnt[idx]){
            puts("NO");
            return 0;
        }
        pint p=lis[idx][cnt[idx]];
        cnt[idx]++;
        if(paint.get(p.first,202020)>=p.second){
            puts("NO");
            return 0;
        }
        ans.pb(p);
        paint.update(p.first,p.second);
    }

    puts("YES");
    rep(i,ans.size())printf("%d %d\n",ans[i].second,ans[i].first);
    return 0;
}