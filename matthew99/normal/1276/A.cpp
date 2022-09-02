#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 150100;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		static char s[maxn + 5];
		scanf("%s", s);
		int n = strlen(s);
		vector<int> ans;
		for (int i = 0; i < n - 2; ++i)
			if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') 
			{
				if (i > 0 && s[i - 1] == 'o') ans.pb(i + 1);
				else ans.pb(i); 
			}
		for (int i = 0; i < n - 2; ++i)
			if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && (s[i + 3] != 'n' || s[i + 4] != 'e')) 
			{
				if (i > 0 && s[i - 1] == 't') ans.pb(i + 1);
				else ans.pb(i); 
			}
		printf("%d\n", SZ(ans));
		for (auto u : ans) printf("%d ", u + 1);
		printf("\n");
	}
	return 0;
}