#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define FORD(i,s,e) for(int i=s;i>=e;i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define MP make_pair
#define EB emplace_back
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int MAXN=11000;
const LL INF=(LL)1e14+69;
vector<LL> pos;
PLL kr[MAXN];
LL dp[MAXN];
LL abso(LL a){return a>0?a:-a;}

main(){
    int n,x;scanf("%d%d",&n,&x);
    pos.PB(x);
    pos.PB(0);
    FOR(i,1,n){
        scanf("%I64d%I64d",&kr[i].e1,&kr[i].e2);
        pos.PB(kr[i].e1);
        pos.PB(kr[i].e2);
    }
    int dl=pos.size();
    sort(ALL(pos));
    FOR(i,0,dl+1){
        dp[i]=INF;
        if(pos[i]==x) dp[i]=0;
    }
    FOR(nr,1,n){
        FOR(i,2,dl)
            dp[i]=min(dp[i],dp[i-1]+abso(pos[i]-pos[i-1]));
        FORD(i,dl-1,1)
            dp[i]=min(dp[i],dp[i+1]+abso(pos[i+1]-pos[i]));
        FOR(i,1,dl){
            if(kr[nr].e1<=pos[i]&&pos[i]<=kr[nr].e2) continue;
            dp[i]+=min(abso(pos[i]-kr[nr].e1),abso(pos[i]-kr[nr].e2));
        }

    }
    LL wyn=INF;
    FOR(i,1,dl) wyn=min(wyn,dp[i]);
    printf("%I64d\n",wyn);
}