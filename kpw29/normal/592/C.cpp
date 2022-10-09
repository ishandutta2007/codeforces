#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define scanf(...) scanf(__VA_ARGS__)?:0
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
#define maxn 1500100
ull a, b, t;

void wypisz(ull a) {
    ull T = t;
    ull dz = __gcd(a, T);
    a/=dz; T/=dz;
    cout<<a<<'/'<<T;
    exit(0);
}

int main()
{
    cin >> t >> a >> b;
    if (a == 1 && b == 1) {
    }
    ull dziel = __gcd(a, b);
    ull A = a/dziel;
    ull dlugosc = min(a,b);
    if (t < dlugosc) {
        puts("1/1");
        exit(0);
    }
    ull NWW = A * b;
    if (NWW / A != b) wypisz(dlugosc-1); //detecting overflow :D
    
    ull ile_razy = (t/NWW);
    ull ostatni = NWW * ile_razy;
    ull WYN = (dlugosc-1)* (ile_razy);
    WYN += ile_razy;
    WYN += min(dlugosc - 1, t - ostatni);
    wypisz(WYN);
    
}