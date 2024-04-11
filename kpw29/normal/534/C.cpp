#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m;
ll suma;
ll SUMA;
int t[milion];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> suma;
    for (int i=1; i<=n; ++i)
    {
        cin >> t[i];
        SUMA += t[i];
    }
    if (n == 1)
    {
        cout << t[1] - 1 << endl;
    }
    else
    {
    for (int i=1; i<=n; ++i)
    {
        ll minimalnie = suma - (SUMA - t[i]) - 1;
        //cout << minimalnie << endl;
        ll maksymalnie = suma - n + 2;
        //cout << maksymalnie << endl;
        ll wyn = max((ll)0, minimalnie) + max((ll)0, t[i] - maksymalnie + 1);
        cout << wyn << ' ';
    }
}
}