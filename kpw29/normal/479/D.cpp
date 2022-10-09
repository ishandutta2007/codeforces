#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

#define maxn 1000100
int t[maxn];
map <int, int> marks;
int n, l, x, y;
ll sum = 0;
bool C1, C2;
bool check(int dl)
{
    for (int i=1; i<=n; ++i) 
    {
        int elem = t[i];
        if (marks[elem - dl] || marks[elem + dl]) return true;
    }
    return false;
}

void c(int help, int foo)
{
    if (marks[foo] || marks[help - foo] || marks[help + foo] || help == foo)
    {
        printf("1\n%d", help);
        exit(0);
    }
    else
    {
        if (x == foo && C1) { printf("1\n%d", help); exit(0); }
        if (y == foo && C2) { printf("1\n%d", help); exit(0); }
    }
}
void c2(int dl)
{
    for (int i=1; i<=n; ++i)
    {
        int elem = t[i];
        if (elem -dl >= 0) c(elem - dl, sum - dl);
        if (dl + elem <= l) c(elem + dl, sum - dl);
        
    }
}
int main()

{
    scanf("%d%d%d%d", &n, &l, &x, &y);
    sum = x + y;
    for (int i=1; i<=n; ++i) scanf("%d", &t[i]), marks[t[i]]++;
    C1 = check(x), C2 = check(y);
    if (C1 && C2) OUT(0);
    c(x, y);
    c(y, x);
    c2(x);
    c2(y);
    printf("2\n");
    printf("%d %d", x, y);
}