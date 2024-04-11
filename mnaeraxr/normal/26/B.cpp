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
const int MAXN = (int)1e6 + 10;

int dp[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int balance = 0;

	stack<pii> S;
	S.push(MP(0,0));
	dp[0] = 0;

	for (int i = 1; i <= SZ(s); ++i){
		if (s[i - 1] == '(') ++balance;
		else --balance;

		while (!S.empty() && S.top().first > balance) S.pop();
		if (!S.empty() && s[i - 1] == ')'){
			int v = i - S.top().second;
			dp[i] = v + dp[i - v];
		}
		else
			dp[i] = dp[i - 1];

//		cout << dp[i] << endl;
		if (S.empty() || S.top().first < balance) S.push(MP(balance, i));
	}

	cout << dp[SZ(s)] << endl;

	return 0;
}