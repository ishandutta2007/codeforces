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

int x[1000], y[1000], n, m;

int rod[1000];
bool use[1000];
int ans[1000];

inline int f(int x) {
    if (x<0) x += n;
    if (x>=n) x -= n;
    return x;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    REP(i,n) scanf("%d%d",&x[i],&y[i]);
    x[n] = x[0], y[n] = y[0];
    REP(i,m) scanf("%d",&rod[i]); 
    
    clean(use);
    
    bool solve = 1;
    
    for (int i = 0; i < n ; i += 2) {
        int cur = abs(x[f(i-1)]-x[i])+abs(y[f(i-1)]-y[i])+abs(x[f(i+1)]-x[i])+abs(y[f(i+1)]-y[i]);
        bool ok = 0;
        REP(j,m) if (!use[j] && rod[j]==cur) {
            use[j] = 1, ans[i] = j+1, ans[f(i-1)] = ans[f(i+1)] = -1;
            ok = 1;
            break;
        }
        if (!ok) solve = 0;
    }
    if (solve) {
        puts("YES");
        REP(i,n) printf("%d ",ans[i]);
        return 0;
    }
    
    solve = 1; clean(use);
    
    for (int i = 1; i < n ; i += 2) {
        int cur = abs(x[f(i-1)]-x[i])+abs(y[f(i-1)]-y[i])+abs(x[f(i+1)]-x[i])+abs(y[f(i+1)]-y[i]);
        bool ok = 0;
        REP(j,m) if (!use[j] && rod[j]==cur) {
            use[j] = 1, ans[i] = j+1, ans[f(i-1)] = ans[f(i+1)] = -1;
            ok = 1;
            break;
        }
        if (!ok) solve = 0;
    }
    if (solve) {
        puts("YES");
        REP(i,n) printf("%d ",ans[i]);
        return 0;
    }
    
    puts("NO");
    
}