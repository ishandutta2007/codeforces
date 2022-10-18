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

const int inf = 10000000;

int d[100][100], use[100][100], ss[100][100], n, k;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    int mid = (k+1)/2;
    FORD(i,1,k) FORD(j,1,k) d[i][j] = abs(i-mid)+abs(j-mid);
    FORD(i,1,k) {
        ss[i][0] = 0;
        FORD(j,1,k) ss[i][j] = ss[i][j-1]+d[i][j];
    }
    clean(use); int x;
    REP(query,n) {
        scanf("%d",&x);
        int best = inf, bx, by;
        FORD(i,1,k) {
            int cons = 0;
            FORD(j,1,k) {if (!use[i][j]) cons++; else cons = 0;
                if (cons>=x && ss[i][j]-ss[i][j-x]<best) {
                    best = ss[i][j]-ss[i][j-x];
                    bx = i, by = j-x+1;
                }
            }
        }
        if (best==inf) {
            printf("-1\n");
        } else {
            printf("%d %d %d\n",bx,by,by+x-1);
            FORD(i,by,by+x-1) use[bx][i] = 1;
        }
    }
}