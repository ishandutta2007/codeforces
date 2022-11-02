#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define rs resize
#define all(v) (v).begin(), (v).end()

const int maxn = 5e3;
int N;
ll A[maxn], B[maxn];

void run() {
	cin >> N;
	REP(i, N) cin >> A[i];
	REP(i, N) cin >> B[i];

	ll ret = 1e9;
	REP(i, N) {
		ll vl = 1e9, vr = 1e9;
		REP(j, N) {
			if (i == j) continue;
			if (j < i && A[j] < A[i])
				vl = min(vl, B[j]);
			else if (i < j && A[i] < A[j])
				vr = min(vr, B[j]);
		}

		ret = min(vl + vr + B[i], ret);
	}
	if (ret >= 1e9)
		cout << "-1" << endl;
	else
		cout << ret << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	run();

	return 0;
}