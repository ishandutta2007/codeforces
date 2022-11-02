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

// returns: (index, moves)
ii solveL(int N, int pos, int target)
{
	// edge case: no tabs to close
	if (target == 1) return ii(pos, 0);

	int time = 0;

	// now, move to target
	time += abs(pos - target);

	// use the trick
	time++;

	return ii(target, time);
}

ii solveR(int N, int pos, int target)
{
	ii sub = solveL(N, N + 1 - pos, N + 1 - target);
	return ii(N + 1 - sub.x, sub.y);
}

void run()
{
	int N, pos, L, R;
	cin >> N >> pos >> L >> R;

	ii sl = solveL(N, pos, L);
	ii sr = solveR(N, pos, R);

	ii srl = solveR(N, sl.x, R); srl.y += sl.y;
	ii slr = solveL(N, sr.x, L); slr.y += sr.y;

	cerr << sl << ", " << sr << endl;
	cerr << srl << ", " << slr << endl;

	cout << min(srl.y, slr.y) << endl;
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