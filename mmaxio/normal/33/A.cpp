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

int worst[1000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, m, k, x, y;
    scanf("%d%d%d",&n,&m,&k);
    
    REP(i,m) worst[i] = 1000001;
    REP(i,n) {
        scanf("%d%d",&x,&y);
        worst[x-1] = min(worst[x-1],y);
    }
    
    int ans = 0;
    REP(i,m) ans += worst[i];
    
    printf("%d",min(ans,k));
}