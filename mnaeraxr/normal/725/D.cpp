#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool compare(pii a, pii b){
	return a.first > b.first;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int64 bal, wei; cin >> bal >> wei;

	vector<pii> V(n - 1);

	for (int i = 0; i < n - 1; ++i)
		cin >> V[i].first >> V[i].second;

	sort(V.begin(), V.end(), compare);

	int best = n;
	int p = 0;	n--;

	priority_queue<int64> pq;

	while (true){
		while (p < n && V[p].first > bal){
			pq.push(- (V[p].second - V[p].first + 1) );
			p++;
		}

		best = min(best, (int)pq.size() + 1);

		if (!pq.empty() && -pq.top() <= bal){
			bal += pq.top();
			pq.pop();
		}
		else
			break;
	}

	cout << best << endl;

	return 0;
}