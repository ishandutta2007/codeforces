#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

map<pair<int,pii>, int> M;
map<int64, int> S;

pair<int,pii> getLine(pii a, pii b){
	int A = b.second - a.second;
	int B = a.first - b.first;
	int C = b.first * a.second - a.first * b.second;

	if (A < 0 || (A == 0 && B < 0)){
		A *= -1; B *= -1; C *= -1;
	}

	int g = max(A, B);
	g = __gcd(A, g);
	g = __gcd(B, g);
	g = __gcd(C, g);
	A /= g, B /= g, C /= g;

	return MP(C, MP(A, B));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> P(n);

	int64 t = 0;
	for (int i = 0; i <= n; ++i){
		t += i;
		S[t] = i;
	}

	for (int i = 0; i < n; ++i){
		cin >> P[i].first >> P[i].second;
		for (int j = 0; j < i; ++j){
			auto line = getLine(P[j], P[i]);
			M[line]++;
		}
	}

	int64 ans = 1LL * n * (n - 1) * (n - 2) / 6;

	for (auto line : M){
		int64 tot = line.second;
		int cur = S[tot] + 1;
		ans -= cur * (cur - 1) * (cur - 2) / 6;
	}

	cout << ans << endl;

	return 0;
}