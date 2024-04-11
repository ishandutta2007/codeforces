#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

vi manacher(vi str)
{
	vi s(2 * SZ(str) + 1);
    fill(ALL(s), 0);
	FOR(i, 0, SZ(str))
	{
		s[2 * i + 1] = str[i];
	}
	vi res(SZ(s));
    fill(ALL(res), 0);
	int l = 1, r = 1;
	FOR(i, 1, SZ(s) - 1)
	{
        // cerr << l << ' ' << r << ' ' << l + r - i << endl;
        if (l + r - i < 0) res[i] = 0;
		else res[i] = min(res[l + r - i], r - i);
		while(i + res[i] + 1 < SZ(s) && i - res[i] - 1 >= 0 && s[i + res[i] + 1] == s[i - res[i] - 1]) res[i]++;
		if (i + res[i] > r)
		{
			l = i - res[i];
			r = i + res[i];
		}
	}
	return res;
}

int TC, N;
vi str;
vi pal;
pii ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        ans = {1, 0};
        string temps;
        cin >> temps;
        N = SZ(temps);
        str.resize(N);
        assert(SZ(str) == N);
        FOR(i, 0, N)
        {
            str[i] = (temps[i] - 'a' + 1);
        }
        pal = manacher(str);
        int mx = 0;
        while(mx < (SZ(str) + 1) / 2 && str[mx] == str[N - mx - 1]) mx++;
        // cerr << "mx = " << mx << endl;
        FOR(i, 1, SZ(pal) - 1)
        {
            //consider this longest palindrome.
            int l = i - pal[i], r = i + pal[i];
            l = (l + 1) / 2; r = (r - 1) / 2;
            if (l > r) continue;
            // cerr << l << ' ' << r << endl;
            //0...l-1 and r+1...N-1
            int len = min(l, N - r - 1);
            // cerr << "len = " << len << endl;
            if (len > mx) continue;
            pii cand;
            if (len == l)
            {
                cand = {r + 1, len};
            }
            else
            {
                cand = {len, N - l};
            }
            if (cand.fi + cand.se > ans.fi + ans.se)
            {
                ans = cand;
                // cerr << "win " << l << ' ' << r << endl;
            }
        }
        if (ans.fi < 0 || ans.se < 0 || ans.fi + ans.se > N) return 0;
        FOR(i, 0, ans.fi)
        {
            if (i < 0 || i >= N) return 0;
            char ch = str[i] + 'a' - 1;
            cout << ch;
        }
        FORD(i, ans.se, 0)
        {
            if (N - 1 - i < 0 || N - 1 - i >= N) return 0;
            char ch = str[N - 1 - i] + 'a' - 1;
            cout << ch;
        }
        cout << '\n';
    }
}