#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, k, a, b, c, p, q, T, steps;

ll sum(ll X)
{
    return X * (X + 1) / 2;
}

int main()
{
    scanf("%d", &T);
    ll N;
    while (T--) {
        cin >> N;
        ll wyn = sum(N);
        ll pot = 1;
        while (pot <= N)
        {
            wyn -= (pot + pot);
            pot += pot;
        }
        cout << wyn << endl;
    }
}