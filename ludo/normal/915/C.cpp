#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ostream& operator<<(ostream &out, const ii &pr) { return out << '(' << pr.x << ',' << pr.y << ')'; }

const bool ONE_TC = true;

void init()
{

}

ll A, B;
int na, nb;
vi a, ca, b;

bool rec(int idx)
{
	int val = b[idx];
	while (val >= 0 && ca[val] == 0)
		val--;

	if (val < 0) return false;

	if (val == b[idx]) {
		// ca[val] > 0
		a[idx] = val;
		ca[val]--;
		if (idx == 0 || rec(idx - 1))
			return true;
		// not succesful, try a smaller value
		ca[val]++;
		a[idx] = 0;

		do val--;
		while (val >= 0 && ca[val] == 0);

		if (val < 0) return false;
	}

	assert(0 <= val && val < b[idx]);

	// fill in greedily
	a[idx] = val;
	ca[val]--;

	for (int j = idx, k = 9; j--; ) {
		while (ca[k] == 0) k--;
		assert(k >= 0);
		a[j] = k;
		ca[k]--;
	}
	return true;
}

void solveA()
{
	assert(na == nb);
	a = vi(na, 0);
	
	assert(rec(nb - 1));
}

void run()
{
	cin >> A >> B;

	a.clear();
	ca = vi(10, 0);
	b.clear();

	while (A > 0LL) { a.pb(A % 10LL); ca[A % 10LL]++; A /= 10LL; }
	while (B > 0LL) { b.pb(B % 10LL); B /= 10LL; }

	na = a.size();
	nb = b.size();

	if (nb <= na) solveA();
	else sort(all(a));

	reverse(all(a));

	assert(na == 1 || a[0] != 0);

	for (int i : a) cout << i;
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	if (ONE_TC) run();
	else {
		int ntc;
		cin >> ntc;
		while (ntc--) run();
	}

	return 0;
}