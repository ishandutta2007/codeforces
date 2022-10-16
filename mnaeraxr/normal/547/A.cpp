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

void end(int64 ans){
	cout << ans << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 m;
	cin >> m;

	int64 h1, a1, x1, y1;
	cin >> h1 >> a1 >> x1 >> y1;

	int64 H2, h2, a2, x2, y2;
	cin >> h2 >> a2 >> x2 >> y2;
	H2 = h2;

	vector<int64> v1(m, -1), v2(m, -1);

	int cur = 0;
	do{
		v1[h1] = cur++;
		h1 = (x1 * h1 + y1) % m;
	} while (v1[h1] == -1);
	int c1 = cur - v1[h1];

	cur = 0;
	do{
		v2[h2] = cur++;
		h2 = (x2 * h2 + y2) % m;
	} while (v2[h2] == -1);

	if (v1[a1] == -1 || v2[a2] == -1)
		end(-1);

	if (v1[a1] == v2[a2])
		end(v1[a1]);

//	if (v1[a1] < v1[h1]) end(-1);
//	if (v2[a2] < v2[h2]) end(-4);

	vector<int64> f(m, -1);
	int64 rf = h2 = H2;
	for (int i = 0; i < c1; ++i)
		rf = (x2 * rf + y2) % m;

	while (f[h2] == -1){
		f[h2] = rf;
		h2 = (x2 * h2 + y2) % m;
		rf = (x2 * rf + y2) % m;
	}

	int64 s = H2;
	for (int i = 0; i < v1[a1]; ++i)
		s = (x2 * s + y2) % m;

	vector<bool> mk(m);

	int64 tot = v1[a1];
	while (!mk[s]){
		mk[s] = true;
		if (s == a2){
			if (v1[a1] < v1[h1] && v1[a1] < tot) end(-1);
			else end(tot);
		}
		s = f[s];
		tot += c1;
	}

	end(-1);

	return 0;
}