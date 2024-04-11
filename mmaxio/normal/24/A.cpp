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

int d[101][3];
int cnt = 0;
int n;
bool was[101];
int ans = 0;

void go(int v, int pr) {
    
    //cerr << v << ' ';
    
    was[v] = 1;
    
    REP(i,n) if (d[i][0]==v) {
        if (!was[d[i][1]]) go(d[i][1],v);
    }

    REP(i,n) if (d[i][1]==v) {
        if (!was[d[i][0]] || (d[i][0] == 1 && pr!=1) ) ans += d[i][2];
        if (!was[d[i][0]]) go(d[i][0],v);   

    }

}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d\n",&n);
    int sum = 0;
    REP(i,n) {
        scanf("%d%d%d",&d[i][0],&d[i][1],&d[i][2]);
        sum += d[i][2];
    }
    clean(was);
    go(1,-1);

    printf("%d",min(ans,sum-ans));
    
    
}