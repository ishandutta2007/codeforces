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

int f(int x, int y) {
    if (x <=0 || y <=0) return 0;
    return (x*y+1)/2;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, m, x;
    scanf("%d%d%d",&n,&m,&x);
    while (n > 0 && m > 0 && x > 1) {
        x--, n -= 2, m -= 2;
    }        

    if (n == 0 || m == 0)
        puts("0");
    else {
        printf("%d",f(n,m) - f(n - 2,m - 2));
    }   
}