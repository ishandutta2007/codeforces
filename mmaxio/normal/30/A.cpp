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

void quit(int x) {
    printf("%d",x);
    exit(0);
}

void fail() {
    puts("No solution");
    exit(0);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int a, b, n;
    scanf("%d%d%d",&a,&b,&n);
    if (b==0) quit(0);
    if (a==0) fail();
    if (b%a != 0) fail();
    int y = b/a;
    if (y < 0 && n%2==0) fail();
    int sign = 1;
    if (y < 0) sign = -1;
    y = abs(y); 

    FORD(ans,1,y) {
        int cnt = 1;
        REP(j,n) cnt *= ans;
        if (cnt>y) fail();
        if (cnt==y) quit(sign*ans);
    }
}