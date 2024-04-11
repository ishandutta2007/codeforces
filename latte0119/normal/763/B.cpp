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

signed main(){
    int N;scanf("%lld",&N);
    vint ans(N);
    rep(i,N){
        int a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        a+=1ll<<40;
        b+=1ll<<40;
        ans[i]=(a%2)*2+b%2;
    }
    puts("YES");
    rep(i,N)printf("%lld\n",ans[i]+1);
    return 0;
}