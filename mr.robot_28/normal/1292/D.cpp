#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MAXK = 5000;
int n; vector<int> cnt(MAXK + 1, 0);
vector<vector<int>> primeExponential(MAXK + 1, vector<int>(MAXK + 1, 0));

void Preprocess() {
	for (int i=2; i<MAXK + 1; i++) {
		for (int j=0; j<MAXK + 1; j++) primeExponential[i][j] += primeExponential[i-1][j];
		int tmp = i;
		for (int x=2; x<=sqrt(tmp); x++) {
			while (tmp % x == 0) {primeExponential[i][x]++; tmp /= x;}
		}
		if (tmp > 1) primeExponential[i][tmp]++;
	}
}

void Input() {
	cin >> n;
	for (int i=0; i<n; i++) {
		int k; cin >> k; cnt[k]++;
	}
}

void Solve() {
	Preprocess();

	vector<int> bestPD(MAXK + 1, 1);
	long long ans = 0, cur = 0;
	for (int i=1; i<MAXK + 1; i++) {
		if (!cnt[i]) {bestPD[i] = 1; continue;}
		for (int j=1; j<MAXK + 1; j++) {
			ans += 1LL * primeExponential[i][j] * cnt[i];
			cur += 1LL * primeExponential[i][j] * cnt[i];
			if (primeExponential[i][j]) bestPD[i] = j;
		}
	}

	while (*max_element(bestPD.begin(), bestPD.end()) > 1) {
		vector<int> frequency(MAXK + 1, 0);

		for (int i=0; i<MAXK + 1; i++) frequency[bestPD[i]] += cnt[i];

		int bestPrime = max_element(frequency.begin(), frequency.end()) - frequency.begin();
		int bestGroup = frequency[bestPrime];
		if (bestGroup * 2 <= n) break;
		if (bestPrime == 1) break;
		cur -= bestGroup; cur += (n - bestGroup); ans = min(ans, cur);

		for (int i=0; i<MAXK + 1; i++) {
			if (bestPD[i] != bestPrime) bestPD[i] = 1;
			if (bestPD[i] == 1) continue;
			primeExponential[i][bestPD[i]] -= 1;
			while (bestPD[i] > 1 && primeExponential[i][bestPD[i]] == 0) bestPD[i]--;
		}
	}

	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}