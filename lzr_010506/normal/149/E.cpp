#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;

char p[N], T[N];
int n, f[N], pos[N], ans, lent;
void getfail()
{
    int j, len = strlen(p);
    f[0] = j = -1;
    rep(i, 1, len - 1)
    {
        while(j >= 0 && p[j + 1] != p[i]) j = f[j];
        if(p[j + 1] == p[i]) j ++;
        f[i] = j;
    }
}
int main()
{
    scanf("%s", T);
    scanf("%d", &n);
    rep(i, 1, n)
    {
        memset(pos, -1, sizeof(pos));
        scanf("%s", p);
        getfail();
        int j = -1, lent = strlen(T), lenp = strlen(p);
	    rep(k, 0, lent - 1)
	    {
	        while(j >= 0 && p[j + 1] != T[k]) j = f[j];
	        if(p[j + 1] == T[k])
	        {
	            j ++;
	            if(pos[j] == -1) pos[j] = k;
	        }
	        if(j + 1 == lenp) break;
	    }
        reverse(p, p + strlen(p));
        reverse(T, T + strlen(T));
        getfail();
        j = -1;
	    rep(k, 0, lent - 1)
	    {
	        while(j >= 0 && p[j + 1] != T[k]) j = f[j];
	        if(p[j + 1] == T[k])
	        {
	            j ++;
	            if(lenp - j - 2 >= 0 && pos[lenp - j - 2] != -1)
	                if(pos[lenp - j - 2] < lent - k - 1)
	                {
	                    ans ++;
	                    break;
	                }
	        }
	    }
        reverse(T, T + strlen(T));
    }
    printf("%d\n",ans);
    return 0;
}