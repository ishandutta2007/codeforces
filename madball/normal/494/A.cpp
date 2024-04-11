#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string in;
	cin >> in;

	if (in[0] == '#') {
		cout << -1;
		return 0;
	}

	int curbal = 0, cnt = 0;
	vector<int> bal(in.size());
	for (int i = 0; i < bal.size(); i++) {
		if (in[i] == '(')
			curbal++;
		if ((in[i] == ')') || (in[i] == '#'))
			curbal--;
		if (in[i] == '#')
			cnt++;
		bal[i] = curbal;
	}
	vector<int> res(cnt);

	vector<int> dp(in.size() + 1);
	dp[dp.size() - 1] = 1e+9;
	for (int i = dp.size() - 2; i >= 0; i--)
		dp[i] = min(bal[i], dp[i + 1]);
	
	int decbal = 0, incdecbal, cur = 0;
	for (int i = 0; i < bal.size(); i++) {
		if (in[i] == '#') {
			if ((i < bal.size() - 1) && (in[i + 1] == '#'))
				incdecbal = 0;
			else
				incdecbal = max(min(bal[i - 1], dp[i] - decbal), 0);
			res[cur] = incdecbal;
			decbal += incdecbal;
			cur++;
		}
		bal[i] -= decbal;
		if (bal[i] < 0) {
			cout << -1;
			return 0;
		}
	}
	
	if (bal[bal.size() - 1] > 0)
		cout << -1;
	else
		for (int i = 0; i < cur; i++)
			cout << res[i] + 1 << '\n';

	return 0;
}