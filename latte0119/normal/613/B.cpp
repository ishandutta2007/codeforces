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

int N,A,X,Y,M;
int a[100000];
int to[100000];
int ansval[100000];

int cost[100000];

signed main(){
    scanf("%lld%lld%lld%lld%lld",&N,&A,&X,&Y,&M);
    vpint vec(N);
    rep(i,N){
        scanf("%lld",&vec[i].fi);
        vec[i].se=i;
    }
    sort(all(vec));reverse(all(vec));

    rep(i,N){
        a[i]=vec[i].fi;
        to[i]=vec[i].se;
    }

    for(int i=N-2;i>=0;i--){
        cost[i]=(a[i]-a[i+1])*(N-i-1)+cost[i+1];
    }

    int ans=0;
    int cur=0;
    while(cur<N&&cost[cur]>M)cur++;
    ans=min(A,(a[cur]+(M-cost[cur])/(N-cur)))*Y;
    pint data(-1,cur);int up=min(A,(a[cur]+(M-cost[cur])/(N-cur)));

    rep(i,N){
        M-=A-a[i];
        if(M<0)break;
        while(cur<N&&(cost[cur]>M||cur<=i))cur++;
        int tmp=(i+1)*X+((i==N-1)?(A*Y):(min(A,(a[cur]+(M-cost[cur])/(N-cur)))*Y));
        if(ans<tmp){
            ans=tmp;
            data=pint(i,cur);
            up=(i==N-1)?A:min(A,(a[cur]+(M-cost[cur])/(N-cur)));
        }
    }
    //cout<<data.fi<<" "<<data.se<<" "<<up<<endl;
    rep(i,data.fi+1)ansval[to[i]]=A;
    reps(i,data.fi+1,data.se)ansval[to[i]]=a[i];
    reps(i,data.se,N)ansval[to[i]]=up;

    printf("%lld\n",ans);
    rep(i,N)printf("%lld ",ansval[i]);
    puts("");
    return 0;
}