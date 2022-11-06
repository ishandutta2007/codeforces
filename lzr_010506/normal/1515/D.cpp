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
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 2e5 + 10;

int L[N], R[N];
int main()
{
    int T = read();
    while(T --)
    {
    	int n = read(), l = read(), r = read();
        rep(i, 1, n) L[i] = R[i] = 0;
        int LL = l, RR = r;
        rep(i, 1, n)
        {
            int x = read();
            if (i <= l) L[x] ++;
            else 
            {
                if (L[x] == 0) R[x] ++;
                else L[x] --, LL --, RR --;
            }
        }
        if (RR > LL)
        {
        	int ans = LL;
            int k = RR - LL;
            rep(i, 1, n)
                while (k && R[i] > 1)
                {
                    k -= 2;
                    R[i] -= 2;
                    ans ++;
                }
            ans += k;
            printf("%d\n", ans);
        }
        else 
        {
            int ans = RR;
            int k = LL - RR;
            rep(i, 1, n)
                while (k && L[i] > 1)
                {
                    k -= 2;
                    L[i] -= 2;
                    ans ++;
                }
            ans += k;
            printf("%d\n", ans);
        }
    }

}