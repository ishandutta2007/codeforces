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

int cost[1001];

int n, x, m, a, b, c;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    int best = -1, root;
    FORD(i,1,n) {
        scanf("%d",&x);
        if (x>best) root = i, best = x;
    }
    
    FORD(i,1,n) cost[i] = 2000000000; cost[root] = 0;
    scanf("%d",&m);
    REP(i,m) {
        scanf("%d%d%d",&a,&b,&c);
        cost[b] = min(cost[b],c);
    }
    int sum = 0;
    FORD(i,1,n) if (cost[i]==2000000000) {
        puts("-1"); return 0;
    } else sum += cost[i];
    printf("%d",sum);
}