#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ld a, b, c;
	cin >> a >> b >> c;
	ld x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	ld ret = abs(x1 - x2) + abs(y1 - y2);

	if (b != 0 && a != 0) {
		// only good if both are non-zero

		ld cx1 = -(c + b * y1) / a;
		ld cx2 = -(c + b * y2) / a;
		ld cy1 = -(c + a * x1) / b;
		ld cy2 = -(c + a * x2) / b;

        ret = min(ret, abs(cx1 - x1) + hypot(cx1 -  x2,  y1 - cy2) + abs(cy2 - y2));
		ret = min(ret, abs(cx1 - x1) + hypot(cx1 - cx2,  y2 -  y1) + abs(cx2 - x2));
		ret = min(ret, abs(cy1 - y1) + hypot(cy1 - cy2,  x1 -  x2) + abs(cy2 - y2));
		ret = min(ret, abs(cy1 - y1) + hypot(cy1 -  y2,  x1 - cx2) + abs(cx2 - x2));
	}

	(cout<<fixed).precision(18);
	cout << ret << endl;
	return 0;
}