#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N, K;
string S;

int loop() {
	cin >> N >> K >> S;
	deque<int> T = { 0 };

	int firstScore = 0;
	rep(i, S.size()) if (S[i] == 'W') firstScore++;
	//rep(i, S.size() - 1)if (S[i] == 'W' && S[i + 1] == 'W') firstScore++;

	int SumL = 0;

	for (char c : S) {
		if (c == 'W') { T.push_back(0); }
		if (c == 'L') { T.back()++; SumL++; }
	}

	if (SumL <= K) return N * 2 - 1;
	if (T.size() == 1) return max(0, K * 2 - 1);

	int LEFT = T.front() + T.back();
	T.pop_back();
	T.pop_front();

	sort(T.begin(), T.end());

	int ans = 0;
	rep(i, T.size()) {
		if (T[i] > K) {
			ans += 2 * K;
			K = 0; break;
		}
		ans += 2 * T[i] + 1;
		K -= T[i];
	}

	ans += 2 * min(LEFT, K);
	return firstScore + ans;
}

int main() {
	int T; cin >> T;
	while (T--) cout << loop() <<endl;

	return 0;
}