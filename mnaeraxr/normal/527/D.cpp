#include <bits/stdc++.h>

using namespace std;

#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)2e5 + 10;

pii pnts[MAXN];
pii STK[MAXN];
int tot;

void view(){
	cout << "----" << endl;
	for (int i = 0; i < tot; ++i)
		cout << STK[i].first << " " << STK[i].second << endl;
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	tot = 0;
	STK[tot++] = MP(0,0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> pnts[i].first >> pnts[i].second;

	sort(pnts, pnts + n);
	for (int i = 0; i < n; ++i){
		pii cur = pnts[i];
		int v = cur.first - cur.second;

		int pos = lower_bound(STK, STK + tot, MP(v,oo)) - STK - 1;
		int val = STK[pos].second + 1;

		while (tot && STK[tot - 1].second <= val && STK[tot - 1].first >= cur.first + cur.second)
			tot--;

		if (val > STK[tot - 1].second)
			STK[tot++] = MP(cur.first + cur.second, val);

//		view();
	}

	cout << STK[tot - 1].second << endl;

	return 0;
}