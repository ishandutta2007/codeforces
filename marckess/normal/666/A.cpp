#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

string s;
vvi dp;
vector<string> vs;

bool obtRes (int i, int k) {
	if (i == s.size())
		return true;

	if (i + k > s.size())
		return false;

	if (dp[i][k] != -1)
		return dp[i][k];

	if (k == 2)
		return dp[i][k] = (obtRes(i+k, 2) && (s[i] != s[i+k] || s[i+1] != s[i+k+1])) 
					  	  || obtRes(i+k, 3);

	return dp[i][k] = obtRes(i+k, 2)
			  	    || (obtRes(i+k, 3) && (s[i] != s[i+k] || s[i+1] != s[i+k+1] || s[i+2] != s[i+k+2]));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	dp = vvi(s.size()+5, vi(5, -1));

	for (int i = 5; i < s.size(); i++) {
		if (obtRes(i, 2)) {
			string xd;
			xd.push_back(s[i]);
			xd.push_back(s[i+1]);

			vs.push_back(xd);
		}

		if (obtRes(i, 3)) {
			string xd;
			xd.push_back(s[i]);
			xd.push_back(s[i+1]);
			xd.push_back(s[i+2]);

			vs.push_back(xd);
		}
	}

	sort(vs.begin(), vs.end());
	vs.erase(unique(vs.begin(), vs.end()), vs.end());

	cout << vs.size() << endl;
	for (auto s : vs)
		cout << s << endl;

	return 0;
}