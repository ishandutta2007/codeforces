#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 1e5 + 10 ;

int q ;
char s1[N] , s2[N] ;

int main() 
{
    int T = read();
    while(T --)
    {
        scanf("%s %s", s1, s2) ;

        int l1 = strlen(s1), l2 = strlen(s2), lef = 0, ned = 0, st = (l1 - l2) & 1;

        rep0(i, l1)
        {
            if (ned == l2) break ;

            if (s1[i] == s2[ned]) 
            {
                if (!ned && (i & 1) == st) {++ ned; lef = 0; continue;}
                else if (ned && !(lef & 1)) {++ ned; lef = 0; continue;}
            }

            ++ lef;
        }

        if (ned == l2) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}