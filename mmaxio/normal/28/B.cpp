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

int perm[100], d[100], c[100], n;

int f(int v) {
    return c[v]==v?v:v = f(c[v]);
}

void uni(int v1, int v2) {
    v1 = f(v1), v2 = f(v2);
    if (v1!=v2) c[v1] = v2;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    REP(i,n) scanf("%d",&perm[i]), perm[i]--; 
    REP(i,n) scanf("%d",&d[i]);
    REP(i,n) c[i] = i;
    REP(i,n) {
        if (i-d[i]>=0) uni(i,i-d[i]);
        if (i+d[i]<n) uni(i,i+d[i]);
    }
    REP(i,n) if (f(i)!=f(perm[i])) {puts("NO"); return 0;}
    puts("YES");
}