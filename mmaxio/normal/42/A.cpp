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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, v;
    int a[100], b[100];
    scanf("%d%d",&n,&v);
    REP(i,n)
        scanf("%d",&a[i]);
    REP(i,n)
        scanf("%d",&b[i]);
    double minX = 1000.0;
    REP(i,n) minX = min(minX, lf(b[i])/a[i]);
    
    double ans = 0;
    REP(i,n) ans += minX*a[i];
    
    printf("%.6lf",min(ans,lf(v)));
}