#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int inf = 1e9+9;
const int mod = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 200100
const ll P = 29;
int n,m, zap, R = 1;
ll A, B, N, M;
ll h1[maxn], h2[maxn];
ll pot[maxn];

char s1[maxn], s2[maxn];

bool rowne(int a, int b, int c, int d)
{
    if (b-a != d-c) return 0;
    int dl = b - a + 1;
    for (int i=0; i<dl; ++i)
      if (s1[a + i] != s2[c + i]) return 0;
    return 1;
}
bool thesame(int a, int b, int c, int d)
{
    if (rowne(a,b, c, d)) return 1;
    int dl1 = b - a + 1, dl2 = d - c + 1;
    if (dl1 & 1 || dl2 & 1) return 0;
    int sr1 = (b +a)>>1, sr2 = (d + c)>>1; {
    bool b1 = (thesame(a, sr1, c, sr2) && thesame(sr1 + 1, b, sr2 + 1, d));
    if (b1) return 1;
    bool b2 = (thesame(a, sr1, sr2 + 1, d) && thesame(sr1 + 1, b, c, sr2));
    if (b1 || b2) return 1;
    return 0;
    }
}
int main()
{
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    int dl = 1;
    while (s1[dl])++dl; --dl;
    int dl2 = 1;
    while (s2[dl2]) ++dl2; --dl2;
    if (dl != dl2) 
    {
        puts("NO");
        return 0;
    }
    pot[0] = 1;
    for (int i=1; i<=dl; ++i) pot[i] = (P * pot[i-1]) % mod;
    h1[0] = h2[0] = 0;
    for (int i=1; i<=dl; ++i)
    {
        h1[i] = (h1[i-1] + pot[i] * (s1[i] - 'a'))%mod;
        h2[i] = (h2[i-1] + pot[i] * (s2[i] - 'a'))%mod;
    }
    
    if (thesame(1, dl, 1, dl)) puts("YES");
    else puts("NO");
    return 0;
}