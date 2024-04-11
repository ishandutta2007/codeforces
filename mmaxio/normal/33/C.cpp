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

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const int inf = 2000000000;

int n, a[100000], pref[100001], suf[100001];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    REP(i,n) scanf("%d",&a[i]);
    
    pref[0] = 0;
    REP(i,n) pref[i + 1] = pref[i] + a[i];
    
    suf[n] = 0;
    FORP(i,n-1,0) suf[i] = suf[i + 1] + a[i];
    
    int best = 0, ans = -inf;
    
    REP(i,n) {
        best = max(best + a[i], -pref[i + 1]);
        
        //cerr << best;     

        ans = max(ans, best - suf[i + 1]);
    }
    
    printf("%d",ans);

}