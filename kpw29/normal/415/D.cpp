#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define maxn 2010
#define pb push_back
typedef long long int ll;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll mod = 1e9+7;
ll t[maxn][maxn];
int n,m,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) t[1][i] = 1;
    for (int i=1; i<k; ++i)
      for (int j=1; j<=n; ++j)
        for (int help=j; help<=n; help+=j) t[i+1][help] = (t[i+1][help] + t[i][j]) %mod;
    ll wyn =0;
    for (int i=1; i<=n; ++i) wyn = (wyn + t[k][i]) %mod;
    cout << wyn%mod;
}