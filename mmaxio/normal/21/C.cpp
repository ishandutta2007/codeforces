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

int n, x[100000];

int d[100000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n); int sum = 0;
    REP(i,n) scanf("%d",&x[i]), sum += x[i];
    if (sum%3!=0) {puts("0"); return 0;}
    int p = sum/3; ll ans = 0;
    
    d[0] = x[0]==p?1:0;
    int tmp = x[0];
    FORD(i,1,n-1) {
        tmp += x[i]; d[i] = d[i-1]; if (tmp==p) d[i]++;
    }
    tmp = 0;
    FORP(i,n-1,2) {
        tmp += x[i]; if (tmp==p) ans += d[i-2];
    }
    
    cout << ans;
}