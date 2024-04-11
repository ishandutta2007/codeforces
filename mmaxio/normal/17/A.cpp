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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, k;
    scanf("%d%d",&n,&k);
    bool prime[1001];
    FORD(i,2,1000) prime[i] = 1;
    FORD(i,2,1000) if (prime[i]) {
        for (int j = i*i; j<=1000; j += i) prime[j] = 0;
    }
    int cnt = 0;
    int prev = 2;
    FORD(i,3,1000) if (prime[i]) {
        int tmp = prev+i+1;
        //cerr << tmp << ' ';
        if (tmp>=2 && tmp<=n && prime[tmp]) cnt++;
        prev = i;
    }             
    puts(cnt>=k?"YES":"NO");
    
}