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

int n, p1, p2, p3, t1, t2;

int f(int x) {
    int res = 0;
    res += min(x,t1)*p1;
    x -= min(x,t1);
    res += min(x,t2)*p2;
    x -= min(x,t2);
    res += x*p3;
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
    int prev, l, r, ans = 0;
    REP(i,n) {
        scanf("%d%d",&l,&r);
        if (i!=0) ans += f(l-prev);
        ans += p1*(r-l); prev = r;
    }
    printf("%d",ans);
}