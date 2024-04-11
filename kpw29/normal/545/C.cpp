#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define maxn 1001000
#define milion 1000100
#define tysiac 1010
#define boost ios_base::sync_with_stdio(false)
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
typedef long double ld;
const ld g = 9.81;
const ld przel  = 3.6;

BONG x[maxn];
int h[maxn];

int gdzie = -(inf + inf);
int main()
{
    int n;
    int wyn = 0;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) scanf("%d %d", &x[i].e1, &x[i].e2);
    sort(x+1, x+n+1);
    x[n+1].e1 = inf + inf;
    for (int i=1; i<=n; ++i)
    {
        if (gdzie < x[i].e1 - x[i].e2) ++wyn, gdzie = x[i].e1;
        else if (x[i].e1 + x[i].e2 < x[i+1].e1) ++wyn, gdzie = x[i].e1 + x[i].e2;
        else gdzie = x[i].e1;
    }
    printf("%d", wyn);
}