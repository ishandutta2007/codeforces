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

int N,D,H;

signed main(){
    scanf("%lld%lld%lld",&N,&D,&H);

    if(H*2<D||D<H)return !printf("-1\n");
    if(N>=3&&D==1)return !printf("-1\n");
    if(N==2&&H==1)return !printf("1 2\n");
    
    int now=2;
    rep(i,H)printf("%lld %lld\n",now-1,now),now++;
    rep(i,D-H)printf("%lld %lld\n",i?now-1:1,now),now++;
    while(now<=N)printf("%lld %lld\n",(int)(1+(H!=1)),now++);
    return 0;
}