#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<bitset>
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define foreach(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define all(c) (c).begin(),(c).end()
#define scanf(...) scanf(__VA_ARGS__)?:0
#define eprintf(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

#define maxn 1000100
ll pref[maxn], suf[maxn];
ll tab[maxn];
int n,k,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> x;
    for (int i=1; i<=n; ++i) cin >> tab[i];
    for (int i=1; i<=n; ++i) pref[i] = (pref[i-1] | tab[i]);
    for (int i=n; i>0; --i) suf[i] = (suf[i + 1] | tab[i]);
    ll MAX = 0;
    for (int i=1; i<=n; ++i)
    {
        ll tmp = tab[i];
        for (int j=0; j<k; ++j) tmp *= x;
        MAX = max(MAX, tmp | pref[i-1] | suf[i+1]);
    }
        cout << MAX;
    
}