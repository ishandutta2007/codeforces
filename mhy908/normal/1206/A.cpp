#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int n, m;
int a[110], b[110];
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=1; i<=m; i++)scanf("%d", &b[i]);
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    printf("%d %d", a[n], b[m]);
}