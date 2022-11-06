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
#define rrep(i, x, y) for(int i = x; i >= y; i --)
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
ll dist2(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return (ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2) + (ll)(z1 - z2) * (z1 - z2);
}
int v[8][3];
bool check()
{
	set<ll> st;
	rep(i, 0, 7)
		rep(j, i + 1, 7)
		{
		    st.insert(dist2(v[i][0], v[i][1], v[i][2], v[j][0], v[j][1], v[j][2]));
		    if(st.size() > 3) return false;
		}

    if(st.size() != 3) return false;
    return true;
}
bool dfs(int x)
{
    if(x == 8) return check();
    do
    {
    	if(dfs(x + 1)) return 1;
    }
    while(next_permutation(v[x], v[x] + 3));
    return 0;
}
int main()
{
    rep(i, 0, 7)
    {
        v[i][0] = read();
        v[i][1] = read();
        v[i][2] = read();
        sort(v[i], v[i] + 3);
    }
    if(!dfs(0)) puts("NO");
    else
    {
        puts("YES");
        rep(i, 0, 7)
            printf("%d %d %d\n",v[i][0],v[i][1],v[i][2]);
    }
    return 0;
}