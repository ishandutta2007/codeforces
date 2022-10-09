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
typedef pair <int, int> PII;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
int tests, n, m, a, b, c, d;

long long tab[1000100];
PII t[1000100];
int main()
{
    boost;
    cin >> n >> d;
    for (int i=1; i<=n; ++i) cin >> t[i].e1 >> t[i].e2;
    if (d == 0) OUT(0);
    sort(t + 1, t + n + 1);
    int j = 1;
    ll sum = 0, wyn = 0;
    for (int i=1; i<=n; ++i)
    {
        sum += t[i].e2;
        while (t[i].e1 - t[j].e1 >= d) sum -= t[j].e2, ++j;
        wyn = max(wyn, sum);
        
    }
    cout << wyn;
    
}