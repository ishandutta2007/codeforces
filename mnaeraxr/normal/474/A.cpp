#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

string s = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int pos(char a)
{
	for (int i = 0; i < (int)s.length(); ++i)
		if (s[i] == a)
			return i;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char M;
	cin >> M;
	int d = (M == 'R') ? -1 : 1;
	string inp;
	cin >> inp;
	for (int i = 0; i < (int)inp.length(); ++i)
	{
		cout << s[pos(inp[i]) + d];
	}
	cout << endl;

	return 0;
}