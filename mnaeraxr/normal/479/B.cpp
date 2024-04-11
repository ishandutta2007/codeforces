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
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (n == 1){
		cout << "0 0" << endl;
		return 0;
	}

	queue<pii> MOVES;
	set<pii> STACK;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		STACK.insert(MP(v, i + 1));
	}

	for (int i = 0; i < k; ++i){
		pii lo = *STACK.begin();
		auto it = STACK.end(); --it;
		pii hi = *it;

		if (hi.first - lo.first <= 1){
			break;
		}

		STACK.erase(lo);
		STACK.erase(hi);
		lo.first++;
		hi.first--;
		MOVES.push(MP(hi.second, lo.second));
		STACK.insert(lo);
		STACK.insert(hi);
	}

	pii lo = *STACK.begin();
	auto it = STACK.end(); --it;
	pii hi = *it;

	cout << hi.first - lo.first << " " << MOVES.size() << endl;

	while (!MOVES.empty()){
		pii cur = MOVES.front(); MOVES.pop();
		cout << cur.first << " " << cur.second << endl;
	}

	return 0;
}