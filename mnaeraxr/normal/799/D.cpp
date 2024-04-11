#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int64 a, b, h, w;
	int n;
	cin >> a >> b >> h >> w >> n;

	vector<int64> e(n);
	for (int i = 0; i < n; ++i)
		cin >> e[i];

	map<pii,int> M;	
	M[ pii(h, w) ] = 0;	
	if (w != h) M[ pii(w, h) ] = 0;
	queue<pii> q; q.push(pii(h,w));
	if (w != h) q.push(pii(w,h));

	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());

	int counter = 0;

	// n = min(n, 34);

	while (!q.empty()){
		counter++;
		auto cur = q.front(); q.pop();
		int t = M[cur];

		if (cur.first >= a && cur.second >= b){
			cout << t << endl;
			return 0;
		}

		if (t == n) continue;

		if (cur.first < a){
			pii ncur(cur.first * e[t], cur.second);
			
			if (M.find(ncur) == M.end()){
				M[ ncur ] = t + 1;
				q.push(ncur);
			}
		}

		if (cur.second < b){
			pii ncur(cur.first, cur.second * e[t]);
			
			if (M.find(ncur) == M.end()){
				M[ ncur ] = t + 1;
				q.push(ncur);
			}
		}
	}
	cout << -1 << endl;

	return 0;
}