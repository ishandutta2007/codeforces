#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define OUT(x) { cout << x; exit(0);}
typedef pair <int, int> PII;
typedef unsigned int ui;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ld;
typedef pair <int, ll> PIL;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = ll(1e18) + 3;
int n,a,b,c,m,k;
ll N,M,A,B,C;

void ustal(int x)
{
    if (x < 10) cout << "0";
}

int main()
{
    boost;
    int a, b; char zn;
    cin >> a >> zn >> b;
    int jed = 60 * a + b;
    cin >> a >> zn >> b;
    int dwa = 60 * a + b;
    jed -= dwa;
    if (jed < 0) jed += 24*60;
    while (jed >= 24*60) jed -= 24*60;
    //cout << jed << endl;
    int W1 = jed % 60;
    jed /= 60;
    ustal(jed);
    cout << jed << ":";
    ustal(W1);
    cout << W1;
    return 0;
}