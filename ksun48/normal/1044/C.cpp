#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<LL,LL> > p(n);
	vector<pair<LL,LL> > q(n);
	for(int i = 0; i < n; i++){
		cin >> p[i].first >> p[i].second;
		q[i].first = p[i].first + p[i].second;
		q[i].second = p[i].first - p[i].second;
	}
	LL xmin = 1LL << 56LL;
	LL ymin = 1LL << 56LL;
	LL xmax = -1LL << 56LL;
	LL ymax = -1LL << 56LL;
	for(int i = 0; i < n; i++){
		xmin = min(xmin, p[i].first);
		xmax = max(xmax, p[i].first);
		ymin = min(ymin, p[i].second);
		ymax = max(ymax, p[i].second);
	}
	LL a4 = xmax - xmin + ymax - ymin;
	LL a3 = 0;
	set<pair<LL,LL> > points;
	for(int i = 0; i < n; i++){
		LL f = max(abs(p[i].first - xmin), abs(p[i].first - xmax)) + 
		max(abs(p[i].second - ymin), abs(p[i].second - ymax));
		a3 = max(a3, f);
	}
	cout << a3 * 2;
	for(int k = 4; k <= n; k++){
		cout << " " << a4 * 2;
	}
	cout << endl;
}