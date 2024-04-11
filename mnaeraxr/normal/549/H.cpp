#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;

//const int oo = 0x3f3f3f3f;
const ld EPS = 1e-40;
const int MAXN = (int)1e5 + 10;
const ld oo = 1e9 + 1e8;

pair<ld,ld> getinterval(ld a, ld b, ld k){
	ld v1 = (a - k) * (b - k);
	ld v2 = (a - k) * (b + k);
	ld v3 = (a + k) * (b - k);
	ld v4 = (a + k) * (b + k);

	ld vmn = min(v1, min(v2, min(v3, v4)));
	ld vmx = max(v1, max(v2, max(v3, v4)));

	return MP(vmn, vmx);
}

bool inside(pair<ld,ld> i, ld p){
	return i.first - EPS < p && p < i.second + EPS;
}

bool valid(ld a, ld b, ld c, ld d, ld k){
	auto p1 = getinterval(a, d, k), p2 = getinterval(b, c, k);
	if (inside(p1, p2.first)) return true;
	if (inside(p1, p2.second)) return true;
	if (inside(p2, p1.first)) return true;
	if (inside(p2, p1.second)) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	ld a, b, c, d;
	cin >> a >> b >> c >> d;

	if (abs(a * d - c * b) < EPS){
		cout << 0 << endl;
		exit(0);
	}


	ld lo = 0, hi = 4000100000.0;

	int MAGIC = 200000;

	for (int i = 0; i < MAGIC; ++i){
		ld mid = (lo + hi) / 2;

		if (valid(a, b, c, d, mid))
			hi = mid;
		else
			lo = mid;
	}

	cout.precision(12);
	cout << fixed << lo << endl;

	return 0;
}