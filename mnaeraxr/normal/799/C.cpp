#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool cmp(pii a, pii b){
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

void fix(vector<pii> &A, int p){
	int t = 0, n = (int)A.size();
	for (int i = 0; i < n && A[i].first <= p; ++i){
		if (t == 0 || A[i].second > A[t - 1].second)
			A[t++] = A[i];
	}
	A.resize(t);
}

int calc(vector<pii> &A, int p){
	sort(A.begin(), A.end());
	vector<pii> B;

	int answer = 0;

	for (auto a : A){
		auto it = upper_bound(B.begin(), B.end(), pii(p - a.first, oo));
		if (it != B.begin()){
			it--;
			answer = max(answer, a.second + it->second);
		}

		if (B.empty() || a.second > B.back().second){
			B.push_back(a);
		}
	}

	return answer;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, c, d;
	cin >> n >> c >> d;

	vector<pii> C, D;

	int x = -1, y = -1;

	for (int i = 0; i < n; ++i){
		int a, b; string X;
		cin >> a >> b >> X;
		if (X == "C") if (b > c) continue;
		if (X == "D") if (b > d) continue;
		if (X == "C") x = max(x, a);
		if (X == "D") y = max(y, a);
		(X == "C" ? C : D).push_back({b, a});
	}

	int answer = (x < 0 || y < 0) ? 0 : x + y;
	answer = max( answer, calc(C, c) );
	answer = max( answer, calc(D, d) );

	cout << answer << endl;

	return 0;
}