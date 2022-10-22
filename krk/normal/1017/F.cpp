#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;

const int Maxm = 17325;
const int Maxn = 10000000;

bool prime[Maxn];
vector <int> pr;
int n;
uint A, B, C, D;
uint res;

uint Reps(uint p)
{
	uint res = 0;
	uint num = n;
	while (num >= p) {
		res += num / p;
		num /= p;
	}
	return res;
}

int main()
{
	fill(prime, prime + Maxn, true);
	for (int i = 2; i < Maxm; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxm; j += i) prime[j] = false;
	} else prime[i] = true;
	cin >> n >> A >> B >> C >> D;
	for (int a = 2; a <= n; a += Maxn) {
		int b = min(n, a + Maxn - 1);
		for (int j = 0; j < pr.size(); j++) {
			int lef = max(2, (a - 1) / pr[j] + 1);
			int rig = b / pr[j];
			if (lef <= rig)
				for (int z = lef * pr[j]; z <= b; z += pr[j])
					prime[z - a] = false;
		}
		for (int j = a; j <= b; j++)
			if (prime[j - a]) {
				uint x = j;
				uint val = ((((A * x) + B) * x) + C) * x + D;
				res += val * Reps(x);
			} else prime[j - a] = true;
	}
	cout << res << endl;
	return 0;
}