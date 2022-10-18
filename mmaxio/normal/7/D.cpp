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

const int max_n = 5000000;

char s[2*max_n+1];
int pi[2*max_n+1];
bool pal[2*max_n+1];
int ans[max_n];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    char c; int n = 0;
    while ((c=gch) != '\n' && c!=EOF) s[n++] = c;
    s[n] = '#';
    for (int i = n+1, j=n-1; j>=0; i++, j--) s[i] = s[j];
    n = 2*n+1;
    pi[0] = 0;
    FORD(i,1,n-1) {
        int q = pi[i-1];
        while (q!=0 && s[i]!=s[q]) q = pi[q-1];
        pi[i] = q;
        if (s[i]==s[q]) pi[i]++;
    }

    //REP(i,n) cerr << (char) s[i]; cerr << '\n';
    //REP(i,n) cerr << pi[i] << ' '; cerr << '\n';
    int uk = pi[n-1];
    clean(pal);
    //ll ans = 0;
    while (uk!=0) {
        //cerr << uk << ' ';
        //if (pi[uk-1] == uk/2 && pi[uk-1]!=0) cnt++; else ans += ll(cnt)*(cnt+1)/2, cnt = 1;
        pal[uk-1] = 1;
        uk = pi[uk-1];
        //cerr << cnt << '\n';
    }

    ll res = 0;

    REP(i,(n-1)/2) {
        if (pal[i])
            ans[i] = ans[(i+1)/2-1]+1;
        else
            ans[i] = 0;
        //cerr << ans[i] << ' ';
        res += ans[i];
    }

    printf("%I64d\n",res);

}