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

int S,T,t;

signed main(){
    scanf("%lld%lld%lld",&S,&T,&t);
    int n;scanf("%lld",&n);
    vint v(n);rep(i,n)scanf("%lld",&v[i]);
    v.pb(LLONG_MAX/10);

    int cur=S;
    int val=LLONG_MAX/10,arc=-1;
    rep(i,v.size()){
        if(cur+t>T)break;
        if(cur<v[i]){
            printf("%lld\n",cur);
            return 0;
        }
        if(val>cur-v[i]+1){
            val=cur-v[i]+1;
            arc=v[i]-1;
        }
        cur+=t;
    }

    printf("%lld\n",arc);
    return 0;
}