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

int N,Q;
int st[100];

int T[111111],K[111111],D[111111];

signed main(){
    scanf("%lld%lld",&N,&Q);
    vpint er;
    rep(i,Q){
        scanf("%lld%lld%lld",&T[i],&K[i],&D[i]);
        er.pb({T[i]+D[i],i});
    }
    sort(all(er));
    int cur=0;
    memset(st,-1,sizeof(st));
    rep(i,Q){
        while(cur<er.size()&&er[cur].fi<=T[i]){
            rep(j,N)if(st[j]==er[cur].se)st[j]=-1;
            cur++;
        }
        vint lis;
        rep(j,N){
            if(st[j]!=-1||lis.size()==K[i])continue;
            lis.pb(j);
        }
        if(lis.size()!=K[i]){
            puts("-1");
            continue;
        }
        int val=0;
        rep(j,lis.size())st[lis[j]]=i,val+=lis[j]+1;
        printf("%lld\n",val);
    }
    return 0;
}