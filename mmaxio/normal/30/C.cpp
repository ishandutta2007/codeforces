#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

struct targ{
    int x, y;
    int tme;
    lf prob;
    targ(int a = 0, int b = 0, int c = 0, lf d = 0.0) {
        x = a, y = b, tme = c, prob = d;
    }
};

bool can(targ &a, targ &b) {
    return sqr(a.x-b.x)+sqr(a.y-b.y)<=sqr(ll(b.tme-a.tme));
}

bool operator< (targ a, targ b) {
    return a.tme < b.tme;
}

targ ls[1000];
lf dp[1000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    REP(i,n) {
        int v1, v2, v3; lf v4;
        scanf("%d%d%d%lf",&v1,&v2,&v3,&v4);
        ls[i] = targ(v1,v2,v3,v4);
    }
    
    lf ans = 0;
    
    sort(ls,ls+n);
    REP(i,n) {
        dp[i] = ls[i].prob;
        REP(j,i) {
            if (can(ls[j],ls[i])) dp[i] = max(dp[i],dp[j]+ls[i].prob);
        }
        ans = max(ans,dp[i]);
    }

    printf("%.10lf",ans);
    
}