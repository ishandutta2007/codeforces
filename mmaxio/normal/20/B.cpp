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
#include <cmath>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int a, b ,c;
    scanf("%d%d%d",&a,&b,&c);
    lf ra = a, rb = b, rc = c;
    if (a==0) {
        if (b==0) {
            if (c==0) puts("-1"); else puts("0");
        } else {
            printf("1\n%.9lf",-rc/rb);
        }
    } else {
        ll D = sqr(ll(b))-4*ll(a)*ll(c);
        if (D<0) {
            puts("0");
        } else if (D==0) {
            printf("1\n%.9lf",-rb/(2*ra));
        } else {
            lf r1 = (-b-sqrt(lf(D)))/(2*ra);
            lf r2 = (-b+sqrt(lf(D)))/(2*ra);
            printf("2\n%.9lf\n%.9lf",min(r1,r2),max(r1,r2));
        }
    }
}