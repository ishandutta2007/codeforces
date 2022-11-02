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

const int SIZE=1000000;
int N;
int A[SIZE],T[SIZE],X[SIZE];

vint qs[SIZE];
int ans[SIZE];


int bit[SIZE+1];
void add(int k,int x){
    for(k++;k<=SIZE;k+=k&-k)bit[k]+=x;
}
int sum(int k){
    int ret=0;
    for(k++;k;k-=k&-k)ret+=bit[k];
    return ret;
}

void solve(int x){
    vint ts;
    rep(i,qs[x].size())ts.pb(T[qs[x][i]]);
    sort(all(ts));ts.erase(unique(all(ts)),ts.end());
    rep(i,qs[x].size()){
        T[qs[x][i]]=lower_bound(all(ts),T[qs[x][i]])-ts.begin();
        int type=A[qs[x][i]];
        if(type==1){
            add(T[qs[x][i]],1);
        }
        else if(type==2){
            add(T[qs[x][i]],-1);
        }
        else{
            ans[qs[x][i]]=sum(T[qs[x][i]]);
        }
    }

    rep(i,qs[x].size()){
        int type=A[qs[x][i]];
        if(type==1){
            add(T[qs[x][i]],-1);
        }
        else if(type==2){
            add(T[qs[x][i]],1);
        }
    }
}

signed main(){
    scanf("%lld",&N);
    vint press;
    rep(i,N){
        scanf("%lld%lld%lld",&A[i],&T[i],&X[i]);
        press.pb(X[i]);
    }
    sort(all(press));
    press.erase(unique(all(press)),press.end());
    rep(i,N){
        X[i]=lower_bound(all(press),X[i])-press.begin();
        qs[X[i]].pb(i);
    }


    rep(i,press.size())solve(i);
    rep(i,N)if(A[i]==3)printf("%lld\n",ans[i]);
    return 0;
}