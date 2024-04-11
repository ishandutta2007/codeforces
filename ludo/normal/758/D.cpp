#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 2e18;
const int MAXN = 100;

ll base, N;
string S;

int ndig[MAXN], prv[MAXN];
ll usedx[MAXN];

ll power(ll exp) {
	ll ret = 1, b = base;
	while (exp) {
		if (exp & 1) {
			ret *= b;
		}
		b *= b;
		exp>>=1;
	}
	return ret;
}

int main()
{
	cin >> base >> S;
	N = S.size();

	ndig[N] = 0;
	prv[N] = 0;
	usedx[N] = 0;

	for (int i = N; i--; ) {
		ndig[i] = MAXN;
		prv[i] = MAXN;
		usedx[i] = INF;

		ll num = 0;
		int j = i;
		do {
			num = 10LL * num + (S[j++] - '0');
			if (num >= base) break;
			prv[i] = j;
			if (ndig[j] + 1 < ndig[i]) {
				// when equal, keep the old solution, because shorter is better!
				ndig[i] = ndig[j] + 1;
				prv[i] = j;
				usedx[i] = num * power(ndig[j]) + usedx[j];
			}
		} while (S[i] != '0' && j < N);
	}
	cout << usedx[0] << endl;
	return 0;
}