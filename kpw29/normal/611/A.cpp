#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const ll mod = 1e9 +7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int k, a, b, c;
inline int readint() 
{
    int x = 0; char c;
    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    for(; c>47 && c<58 ; c = getchar()) x = (x<<1) + (x<<3) + c - '0';
    return x;
}
int months[20];
int main()
{
    ll n = readint();
    char zn;
    
    zn = getchar();
    zn = getchar();
    zn = getchar();
    zn = getchar();
    months[1] = 31;
    months[2] = 29;
    months[3] = 31;
    months[4] = 30;
    months[5] = 31;
    months[6] = 30;
    months[7] = 31;
    months[8] = 31;
    months[9] = 30;
    months[10] = 31;
    months[11] = 30;
    months[12] = 31;
    ll res = 0;
    if (zn == 'm')
    {
        for (int i=1; i<=12; ++i)
          if (n <= months[i]) ++res;
          cout << res;
    }
    else
    {
        if (n == 5 || n == 6) cout << 53;
        else cout << 52;
    }
}