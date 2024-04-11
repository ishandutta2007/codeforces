#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	string cd = "CODEFORCES";

	int len1 = 0, len2 = 0;

	for (int i = 0; i < (int)s.length() && i < (int)cd.length() ; ++i)
	{
		if (s[i] == cd[i]) ++len1;
		else break;
	}

	for (int i = 0; i < (int)s.length() && i < (int)cd.length() ; ++i)
	{
		if (s[(int)s.length() - 1 - i] == cd[ (int)cd.length() - 1 - i]) ++len2;
		else break;
	}

	if (len1 + len2 >= (int)cd.length())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}