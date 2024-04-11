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

const int inf = 1000000;

typedef long long ll;
typedef double lf;

string as, bs;
int a[100000], b[100000], cost[26][26];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    getline(cin,as);
    getline(cin,bs);
    if (sz(as) != sz(bs)) {
        puts("-1");
        return 0;
    }
    int n = sz(as);

    REP(i,n) a[i] = as[i] - 'a', 
             b[i] = bs[i] - 'a';

    
    int m;

    scanf("%d\n",&m);
    REP(i,26) REP(j,26) cost[i][j] = i==j ? 0 : inf;

    REP(i,m) {
        char c1, c2; int val;
        scanf("%c %c %d\n",&c1,&c2,&val);
        cost[c1-'a'][c2-'a'] = min(cost[c1-'a'][c2-'a'], val);
    }
    
    REP(k,26) REP(i,26) REP(j,26) cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        
    string res(n,'?');
    int ans = 0;
    
    REP(i,n) {
        int best = inf;
        char repl;
        REP(j,26) if (cost[a[i]][j] + cost[b[i]][j] < best) {
            best = cost[a[i]][j] + cost[b[i]][j];
            repl = 'a' + j;
        }

        if (best == inf) {
            puts("-1"); return 0;
        }
        res[i] = repl; ans += best;
    }
    
    printf("%d\n",ans);
    
    cout << res;
    
    
}