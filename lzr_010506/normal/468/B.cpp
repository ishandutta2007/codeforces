#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
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

const int N=1e5+5;
int n,a,b,p[N],fa[N];
map<int,int> mp;

int Find(int x)
{
    if(fa[x] == x) return fa[x];
    return fa[x] = Find(fa[x]);
}

void Union(int u,int v)
{
    int uu = Find(u);
    int vv = Find(v);
    if(uu != vv) fa[uu] = v;
}

int main()
{
	n = read();
	a = read();
	b = read();
    int Max = 0;
    rep(i, 1, n)
    {
        p[i] = read();
        mp[p[i]] = i;
        Max = max(Max, p[i]);
    }
    if(Max >= max(a, b)) printf("NO\n");
    else
    {
        rep(i, 0, n + 1) fa[i] = i;
        rep(i, 1, n)
        {
            if(mp[a - p[i]]) Union(i, mp[a - p[i]]);
            else Union(i, n + 1);
            if(mp[b - p[i]]) Union(i, mp[b - p[i]]);
            else Union(i, 0);
        }
        int A = Find(0);
        int B = Find(n + 1);
        if(A != B)
        {
            printf("YES\n");
            rep(i, 1, n)
           		if(Find(i) == A) printf("0 ");
                else printf("1 ");
        }
        else printf("NO\n");
    }
    return 0;
}