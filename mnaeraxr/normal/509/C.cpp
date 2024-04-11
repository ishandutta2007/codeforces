#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

string ans;
bool ok;

void dfs(int p, int sum, bool flag, string cur)
{
	if (p == SZ(ans))
	{
		if (sum == 0 && flag){
			ok = true;
			ans = cur;
		}
		return;
	}

	if ( (SZ(ans) - p) * 9 < sum) return;

	for (int i = 0; i < 10; ++i){
		if (i > sum) return;

		if (flag) dfs(p + 1, sum - i, flag, cur + (char)('0' + i));
		else{
			if (i == ans[p] - '0') dfs(p + 1, sum - i, 0, cur + (char)('0' + i));
			else if (i > ans[p] - '0') dfs(p + 1, sum - i, 1, cur + (char)('0' + i));
		}

		if (ok) return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q; cin >> q;

	ans = "";

	while (q--){
		int s; cin >> s;

		while (true){
			dfs(0, s, 0, "");
			if (ok){
				ok = false;
				cout << ans << endl;
				break;
			}
			ans = "0" + ans;
		}
	}

	return 0;
}

// From For_the_Love