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
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 9;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct Node
{
	int x, y;
}a[N];
int n;
map<pair<int, int>, int> Mp;
set <int> st;
int res[N];
int up[3][2] = {{0, 1}, {-1, 1}, {1, 1}};
int down[3][2] = {{0, -1}, {-1, -1}, {1, -1}};

int gcount(const pii& t)
{
    int x, y;
    int ret = 0;
    rep(i, 0, 2)
    {
        x = t.X + down[i][0], y = t.Y + down[i][1];
        pii tmp = mp(x, y);
        if(Mp.find(tmp) != Mp.end()) ret ++;
    }
    return ret;
}

bool candes(int i)
{
    bool flag = true;
    int x, y;
    rep(j, 0, 2)
    {
        x = a[i].x + up[j][0], y = a[i].y + up[j][1];
        pii tmp = mp(x, y);
        if(Mp.find(tmp) != Mp.end() && gcount(tmp) <= 1)
            return false;
    }
    return true;
}

int low()
{
    auto it = st.begin();
    int tmp;
    while(!st.empty())
    {
        it = st.begin();
        if(candes(*it))
        {
            tmp = *it;
            st.erase(it);
            break;
        }
        st.erase(it);
    }
    Mp.erase(make_pair(a[tmp].x, a[tmp].y));
    int x, y;
   	rep(i, 0, 2)
    {
        x = a[tmp].x + down[i][0], y = a[tmp].y + down[i][1];
        pii tp = make_pair(x, y);
        auto it = Mp.find(tp);
        if(it != Mp.end() && candes(it -> Y))
            st.insert(it -> Y);
    }
    return tmp;
}
int upp()
{
    auto it = st.end();
    int tmp;
    while(!st.empty())
    {
        it = st.end();
        it--;
        if(candes(*it))
        {
            tmp = *it;
            st.erase(it);
            break;
        }
        st.erase(it);
    }

    Mp.erase(make_pair(a[tmp].x, a[tmp].y));

    int x, y;
    rep(i, 0, 2)
    {
        x = a[tmp].x + down[i][0], y = a[tmp].y + down[i][1];
        pii tp = make_pair(x, y);
        auto it = Mp.find(tp);
        if(it != Mp.end() && candes(it -> Y))
            st.insert(it -> Y);
    }
    return tmp;
}

int main()
{
	n = read();
	rep(i, 0, n - 1)
	{
		int x = read();
		int y = read();
		a[i] = (Node){x, y};
		Mp[mp(x, y)] = i;
	}
	rep(i, 0, n - 1)
   		if(candes(i)) st.insert(i);
    rep(i, 0, n - 1)
   	    res[i] = i & 1 ? low() : upp();
    ll ret = 0, xx = 1;
    for(int i = n - 1; i >= 0; i --)
    {
        ret = (ret + (ll)res[i] * xx) % MOD;
        xx = (xx * n) % MOD;
    }
    cout << ret;
	return 0;
}