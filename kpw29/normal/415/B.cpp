#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
typedef long long int ll;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
typedef unsigned int ui;
typedef unsigned long long ull;

int n,m;
long long a,b;
#define maxn 200
int t[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i=1; i<=n; ++i)
    {
        ll w;
        cin >> w;
        ll k = (w * a)/b;
        ll wart = (k * b + a - 1)/a;
        cout << w - wart << ' ';
    }
}