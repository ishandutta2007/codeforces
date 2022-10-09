#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
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
int n,m,a,b;
set <ll> q;
int main()
{
    int a;
    for (ll i=1; i<=100000; ++i) q.insert(i * (i + 1) / 2);
    scanf("%d", &n);
    bool czy =false;
    for (ll i=1; i<=100000; ++i)
    {
        ll nasz = i * (i + 1) / 2;
        ll ile = n - nasz;
        if (q.find(ile) != q.end()) czy =true;
    }
    if (czy) puts("YES");
    else puts("NO");
    
    return 0;
}