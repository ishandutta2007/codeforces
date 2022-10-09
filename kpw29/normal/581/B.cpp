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

int n,m,k,a,b,c;
int t[1000100];

int main()
{
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> t[i];
    vector <int> w;
    w.clear();
    int maks = 0;
    for (int i=n; i>0; --i)
    {
        w.pb(max(0, maks - t[i] + 1));
        maks = max(maks, t[i]);
    }
    for (int i=w.size() - 1; i>=0; --i) printf("%d ", w[i]);
}