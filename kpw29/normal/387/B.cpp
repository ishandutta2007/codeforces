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
#define maxn 1000100
vector <PII> v;
int main()
{
    boost;
    cin >> n >> k;
    for (int i=1; i<=n; ++i)
    {
        cin >> a;
        v.pb(mp(a, -1));
    }
    for (int i=1; i<=k; ++i)
    {
        cin >> a;
        v.pb(mp(a, 1));
    }
    sort(v.begin(), v.end());
    int nums = 0;
    int wyn = 0;
    for (int i=v.size() - 1; i>=0; --i)
    {
        int akt = v[i].e2;
        if (akt == 1) nums++;
        else if (nums > 0) nums--;
            else wyn++;
    }
    cout << wyn;
}