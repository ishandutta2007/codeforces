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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n,m,k,a,b,c;
char s[maxn];

int main()
{
    scanf("%d", &n);
    scanf("%s", s+1);
    char akt = s[1];
    int wyn = 1;
    for (int i=2; i<=n; ++i)
    {
        if (akt != s[i]) ++wyn;
        akt = s[i];
    }
    printf("%d", min(n, wyn + 2));
}