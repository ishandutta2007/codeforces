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

int n; ll m;
int x[100000], y[100000];

ll tmp[100000];

ll solve(int d0, int d[]) {
    tmp[0] = 0;
    REP(i,n) tmp[i+1] = 2*ll(d[i])-tmp[i];
    ll full = m/n, rem = m%n;
    if (full%2==1) d0 = tmp[n]-d0;
    if (rem%2==1) d0 = tmp[rem]-d0; else d0 = tmp[rem]+d0;
    return d0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d%I64d",&n,&m);
    ll x0, y0;
    scanf("%I64d%I64d",&x0,&y0);
    REP(i,n) scanf("%d%d",&x[i],&y[i]);
    printf("%I64d %I64d",solve(x0,x),solve(y0,y));
}