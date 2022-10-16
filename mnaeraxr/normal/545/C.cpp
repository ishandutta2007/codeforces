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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int last = -oo, ans = 1;
	int x, h, xp, hp;
	bool prev = false;

	cin >> last >> h;

	for (int i = 1; i < n; ++i){
		cin >> x >> h;

		if (prev){
			prev = false;
			if (xp + hp < x){
				++ans;
				last = xp + hp;
			}
		}

		if (x - h > last){
			++ans;
		}
		else{
			xp = x, hp = h;
			prev = true;
		}
		last = x;
	}

	if (prev) ++ans;

	cout << ans << endl;

	return 0;
}