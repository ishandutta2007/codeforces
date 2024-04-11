#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<string> ans;

string get_next(string a, string b){
	if (a.length() > b.length()) return "-";

	if (a == "0" || a.length() < b.length()){
		for (int i = 0; i < b.length(); ++i)
			if (b[i] == '?') b[i] = (i ? '0' : '1');
		return b;
	}
	else{
		vector<bool> dp(b.length());
		for (int i = b.length() - 1; i >= 0; --i){
			if (b[i] == '?'){
				if (a[i] < '9') dp[i] = true;
				else dp[i] = i == b.length() - 1 ? false : dp[i + 1];
			}
			else{
				if (a[i] == b[i])
					dp[i] = i == b.length() - 1 ? false : dp[i + 1];
				else
					dp[i] = b[i] > a[i];
			}
		}

		if (!dp[0]) return "-";

		bool iG = false;
		for (int i = 0; i < b.length(); ++i){
			if (b[i] == '?'){
				if (iG) b[i] = '0';
				else if (i < b.length() - 1 && dp[i + 1])
					b[i] = a[i];
				else{
					b[i] = a[i] + 1;
					iG = true;
				}
			}
			else{
				if (b[i] > a[i])
					iG = true;
			}
		}		

		return b;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string p = "";

	bool ok = true;

	for (int i = 0; i < n && ok; ++i){
		string s; cin >> s;
		s = get_next(p, s);
		if (s == "-") ok = false;
		ans.push_back(s);
		p = s;
	}

	if (ok){
		cout << "YES" << endl;
		for (auto t : ans)
			cout << t << endl;
	}
	else{
		cout << "NO" << endl;
	}


	return 0;
}