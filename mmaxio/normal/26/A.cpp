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

bool prime[3001];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    prime[1] = 0;
    FORD(i,2,3000) prime[i] = 1;
    for (int i=2; i*i<=3000; i++) {
        for (int j = i*i; j<=3000; j += i) prime[j] = 0;
    }
    int n;
    scanf("%d",&n); int ans = 0;
    FORD(i,1,n) {
        int cnt = 0;
        FORD(j,1,i) if (prime[j] && i%j==0) cnt++;
        if (cnt==2) ans++;
    }
    printf("%d",ans);
}