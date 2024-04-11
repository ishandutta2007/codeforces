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

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int f(int n, int x) {
    int res = (9+n-x)/9;
    if (x==0) res--;
    return res;
}

int n;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    ll res = 0;
    REP(i,9) REP(j,9) {
        int c1 = f(n,i), c2 = f(n,j), c3 = f(n,i*j%9);
        res += ll(c1)*c2*c3;
    }
    //cerr << res;
    FORD(i,1,n) res -= n/i;
    printf("%I64d",res);
}