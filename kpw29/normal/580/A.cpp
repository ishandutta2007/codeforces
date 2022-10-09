#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
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
int tests, n, m, a, b, c;

long long tab[1000100];

int main()
{
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> tab[i];
    int wyn = 0;
    int akt = 1;
    for (int i=2; i<=n; ++i)
    {
        if (tab[i] >= tab[i-1]) ++akt;
        else akt = 1;
        wyn = max(wyn, akt);
    }
    wyn = max(wyn, akt);
    cout << wyn;
}