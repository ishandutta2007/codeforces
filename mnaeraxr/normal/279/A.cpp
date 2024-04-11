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

bool inside(pii a, pii b, pii c){
	return min(a.first, b.first) <= c.first && c.first <= max(a.first, b.first) &&
		   min(a.second, b.second) <= c.second && c.second <= max(a.second, b.second);
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	pii cur, e;
	cin >> e.first >> e.second;
	cur = {0, 0};
	int turn = 0, step = 0;
	for (;;++turn){
		if (turn % 2 == 0) ++step;
		pii nxt = {cur.first + step * dx[turn % 4], cur.second + step * dy[turn % 4]};
		if (inside(cur, nxt, e)){
			cout << turn << endl;
			break;
		}
		cur = nxt;
	}

	return 0;
}