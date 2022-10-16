#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int64 mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int64 w, h;
	cin >> n >> h >> w;
	string s;
	cin >> s;

	int64 x1 = 1, y1 = 1, x2 = w, y2 = h;
	int64 ans = 0;

	for (int i = 0; i < n; ++i){
		char c = s[i];
		if (c == 'U'){
			y1++; y2++;
			if (y2 > h){
				y2 = h;
				ans = (ans + 1LL * (i + 1) * (x2 - x1 + 1) % mod) % mod;
			}
		}
		else if (c == 'D'){
			y1--; y2--;
			if (y1 < 1){
				y1 = 1;
				ans = (ans + 1LL * (i + 1) * (x2 - x1 + 1) % mod) % mod;
			}
		}
		else if (c == 'L'){
			x1--; x2--;
			if (x1 < 1){
				x1 = 1;
				ans = (ans + 1LL * (i + 1) * (y2 - y1 + 1) % mod) % mod;
			}
		}
		else if (c == 'R'){
			x1++; x2++;
			if (x2 > w){
				x2 = w;
				ans = (ans + 1LL * (i + 1) * (y2 - y1 + 1) % mod) % mod;
			}
		}

		if (x1 > x2 || y1 > y2){
			cout << ans << endl;
			exit(0);
		}
	}

	vector<pii> events;
	vector<int64> size = {x2 - x1 + 1, y2 - y1 + 1};

	for (int i = 0; i < n; ++i){
		char c = s[i];
		if (c == 'U'){
			y1++; y2++;
			if (y2 > h){
				events.push_back({1, i + 1});
				y2 = h;
			}
		}
		else if (c == 'D'){
			y1--; y2--;
			if (y1 < 1){
				events.push_back({1, i + 1});
				y1 = 1;
			}
		}
		else if (c == 'L'){
			x1--; x2--;
			if (x1 < 1){
				events.push_back({0, i + 1});
				x1 = 1;
			}
		}
		else if (c == 'R'){
			x1++; x2++;
			if (x2 > w){
				events.push_back({0, i + 1});
				x2 = w;
			}
		}
	}

	if (events.empty()){
		cout << -1 << endl;
		exit(0);
	}

	int tot = (int)events.size();
	int64 r = 0;
	for (int i = 0; size[0] && size[1]; i = i + 1 == tot ? 0 : i + 1){
		if (i == 0) r += n;
		int s = events[i].first;
		int64 tt = events[i].second;
		ans = (ans + (r + tt) * size[s ^ 1] % mod) % mod;
		size[s]--;
	}

	cout << ans << endl;

	return 0;
}