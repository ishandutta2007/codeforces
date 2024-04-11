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
#include <set>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

set<int> x;

int pos[3];

bool can(int diam) {
    set<int>::iterator cur = x.begin();
    REP(i, 3) {
        if (cur == x.end()) {
            pos[i] = 1;
            continue;
        }
        pos[i] = *cur;
        cur = x.upper_bound(*cur + diam);
    }
    return cur == x.end();
}

void outp(ll x) {
    printf("%d",x / 2);
    printf(x % 2 == 1 ? ".5" : ".0");
    printf("00000");
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, tmp;
    scanf("%d\n",&n);
    REP(i, n) scanf("%d",&tmp), x.insert(tmp);
    if (sz(x) <= 3) {
        puts("0.000000");
        for (set<int>::iterator it = x.begin(); it != x.end(); it++)
            printf("%d.000000 ",*it);
        REP(i, 3 - sz(x)) printf("%d ",*(x.begin()));
        return 0;
    }
    int l = 0, r = 400000000;//it is DIAMETER
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (can(mid)) r = mid;
        else l = mid;
    }
    //printf("%d", r);
    can(r);//it should return true  
    outp(r); pch('\n');
    REP(i, 3) {
        outp(2ll * pos[i] + r); pch(' ');
    }
}