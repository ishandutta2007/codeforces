#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define e2 second
#define maxn 500100
#define e1 first
const int inf = 2e9;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
int n,a,b,c,m;
char s[1000100];
int t[maxn][6];
int av[maxn][6];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j )scanf("%d", &t[i][j]);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j) av[i][j] =  max(av[i-1][j] + t[i-1][j], av[i][j-1] + t[i][j-1]);
    for (int i=1; i<=n; ++i) printf("%d ", av[i][m] + t[i][m]);
}