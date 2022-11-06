#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
#define N 200010
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, k;
string s[5555];
int good = 1;
int cnt[5555];

int ok(int l, int r)
{
	for(int i = 1; i < k; i++)
	{
		int cc = cnt[i];
		if(s[0][l] != s[i][l]) cc--;
		if(s[0][r] != s[i][r]) cc--;
		if(s[0][l] != s[i][r]) cc++;
		if(s[0][r] != s[i][l]) cc++;
		if(cc == 2) continue;
		if(cc == 0 && good) continue;
		return 0;
	}
	return 1;
}

int main ()
{
	cin >> k >> n;
	set<char>S;
	for(int i = 0;  i<k; i++)
		cin >> s[i];

	set<string> C;
	for(int i = 0; i < n; i++)
		S.insert(s[0][i]);

	for(int i = 0; i < k; i++)
	{
		string t =s[i];
		sort(t.begin(), t.end());
		C.insert(t);
	}
	if(C.size() != 1)
	{
		cout << -1 << endl;
		return 0;
	}
	if(k == 1)
	{
		swap(s[0][n-1], s[0][0]);
		cout << s[0]<<endl;
		return 0;
	}

	if(S.size() == n) good = 0;
	for(int i = 1; i < k; i++)
		for(int j = 0; j < n; j++)
			if(s[0][j] != s[i][j]) cnt[i]++;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(ok(i, j))
			{
				swap(s[0][i], s[0][j]);
				cout << s[0] << endl;
				return 0;
			}
	cout << -1<<endl;
    return 0;
}