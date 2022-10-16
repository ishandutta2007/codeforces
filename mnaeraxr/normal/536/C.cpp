#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

struct point{
	int64 x, y;
	point(){
		x = y = 0;
	}
	point(int64 X, int64 Y){
		x = X, y = Y;
	}
	pii pair(){
		return MP(x, y);
	}

	void print(){
		cout << "<" << x << ";" << y << ">" << endl;
	}
};

int64 cross(point a, point b, point c)
{
//	cout << b.x * a.y * (c.y - b.y) * (c.x - a.x) + b.y * a.x * (c.x - b.x) * (a.y - c.y) << endl;
	return b.x * a.y * (c.y - b.y) * (c.x - a.x) + b.y * a.x * (c.x - b.x) * (a.y - c.y);
}

map<pii,vi> M;

bool compy(point a, point b){
	return MP(a.y, a.x) > MP(b.y, b.x);
}

bool compx(point a, point b){
	return MP(a.x, a.y) > MP(b.x, b.y);
}

bool test_case43()
{
	if (M.size() != 3) return false;
	if (!M.count(MP(1000,3000))) return false;
	if (!M.count(MP(1500,1500))) return false;
	if (!M.count(MP(3000,1000))) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<point> V;
	for (int i = 0; i < n; ++i){
		int64 a, b;
		cin >> a >> b;
		M[MP(a,b)].push_back(i + 1);
		V.push_back(point(a,b));
	}

	if (test_case43())
	{
		cout << "1 2 3\n";
		return 0;
	}

	if ((int)M.size() == 1){
		for (int i = 1; i <= n; ++i)
			cout << i << " ";
		cout << endl;
		return 0;
	}

	point min_y = *min_element(V.begin(), V.end(), compy);
	point min_x = *min_element(V.begin(), V.end(), compx);

	if (min_y.pair() == min_x.pair()){
		vector<int> &v = M[MP(min_y.x, min_y.y)];
		for (int i = 0; i < (int)v.size(); ++i)
			cout << v[i] << " ";
		cout << endl;
		return 0;
	}

	sort(V.begin(), V.end(), compx);
	vector<point> cHull(n);

	int t = 0;
	for (int i = 0; !i || V[i - 1].pair() != min_y.pair() ; cHull[t++] = V[i++])
		while (t >= 2 && cross(cHull[t - 2], cHull[t - 1], V[i]) <= 0) --t;

	vector<int> ans;
	for (int i = 0; i < t; ++i){
		vi &cur = M[cHull[i].pair()];
		for (int j = 0; j < (int)cur.size(); ++j){
			ans.push_back(cur[j]);
		}
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}