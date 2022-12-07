#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define eb emplace_back

const long long INF = 2e9 + 5;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main() 
{
    int n, k, s, t;
    n = read();
    k = read();
    s = read();
    t = read();
    vector<pair<int, int> > v;

    for (int i = 0; i < n; i ++) 
    {
        int c, vt;
        c = read();
        vt = read();
        v.eb(vt, c);
    }
    sort(v.begin(), v.end());
    for (int i = ((int) v.size()) - 2; i >= 0; i--) v[i].S = min(v[i].S, v[i + 1].S);

    vector<int> st;
    for (int i = 0; i < k; i ++) 
    {
        int x;
        x = read();
        st.pb(x);
    }
    st.pb(s);
    sort(st.begin(), st.end());

    int l = 0;
    int r = ((int) v.size()) - 1;
    int ans = -1;
    while (l <= r) 
    {
        int mid = (l + r) / 2;
        int fuel = v[mid].F;
        long long mintime = 0;
        int pos = 0;
        for (int i : st) 
        {
            int dist = i - pos;
            if (dist > fuel) 
            {
                mintime = INF;
                break;
            }
            int f1 = 0;
            int f2 = 0;
            if (dist * 2ll <= fuel) f2 = dist;
            else {
                f2 = fuel - dist;
                f1 = dist - f2;
            }
            mintime += f2 + f1 * 2ll;
            pos = i;
        }
        if (mintime <= t) 
        {
            ans = v[mid].S;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}