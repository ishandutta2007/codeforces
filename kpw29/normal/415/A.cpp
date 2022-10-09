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

int n,m,k;
#define maxn 200
int t[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int j=1; j<=m; ++j)
    {
        int a;
        cin >> a;
        for (int i=a; i<=n; ++i) if (t[i] == 0) t[i] = a;
    }
for (int i=1; i<=n; ++i) cout << t[i] << ' ';
}