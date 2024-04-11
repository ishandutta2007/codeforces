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

struct BIT{
    int N;
    vint ma;
    void init(int n){
        N=n;
        ma.resize(N+1,0);
    }
    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)chmax(ma[k],x);
    }
    int get(int k){
        int ret=0;
        for(k++;k;k-=k&-k)chmax(ret,ma[k]);
        return ret;
    }
};

int N;
int A[100000];
BIT bit;

int ord[100000];

signed main(){
    scanf("%lld",&N);
    rep(i,N){
        int r,h;scanf("%lld%lld",&r,&h);A[i]=r*r*h;
    }
    bit.init(N+114);

    vpint vec;
    rep(i,N)vec.pb(pint(A[i],i));
    sort(all(vec));
    rep(i,N)ord[vec[i].se]=i;
    rep(i,N){
        int lb=-1,ub=ord[i];
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(vec[mid].fi==vec[ord[i]].fi)ub=mid;
            else lb=mid;
        }
        int tmp=bit.get(lb);
        bit.add(ord[i],tmp+A[i]);
    }

    printf("%.20f\n",acos(-1)*bit.get(N-1));
    return 0;
}