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
const int MAXN = (int)2e5 + 10;

int64 BIT[MAXN];

void update(int idx){
	while (idx < MAXN){
		BIT[idx]++;
		idx += idx & -idx;
	}
}

int64 read(int idx){
	int64 ans = 0;
	while (idx){
		ans += BIT[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int64 count_inversion(vi &V)
{
	vector<pii> val(SZ(V));
	for (int i = 0; i < SZ(V); ++i)
		val[i] = MP(V[i], i + 1);
	sort(val.begin(), val.end());
	int64 ans = 0;

	for (int i = SZ(V) - 1; i >= 0; --i){
		ans += read(val[i].second);
		update(val[i].second);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> Q(n);
	vector<int> C;
	map<int,int> M;

	for (int i = 0; i < n; ++i){
		cin >> Q[i].first >> Q[i].second;
		if (!M.count(Q[i].first)){
			M[Q[i].first] = -1;
			C.push_back(Q[i].first);
		}
		if (!M.count(Q[i].second)){
			M[Q[i].second] = -1;
			C.push_back(Q[i].second);
		}
	}

	int64 ans = 0;

	sort(C.begin(), C.end());
	vi S = C;
	for (int i = 0; i < SZ(C); ++i)
		M[C[i]] = i;

	vector<int> V(SZ(C));
	for (int i = 0; i < SZ(C); ++i)
		C[i] = i;

	for (int i = 0; i < n; ++i){
		swap(C[ M[Q[i].first] ], C[ M[Q[i].second] ] );
	}

	for (int i = 0; i < SZ(C); ++i){
		if (i == C[i]) continue;
		if (i < C[i]){
			ans += S[ C[i] ] - S[i] - (C[i] - i);
		}
		else{
			ans += S[i] - S[C[i]] - (i - C[i]);
		}
	}

	ans += count_inversion(C);

	cout << ans << endl;

	return 0;
}